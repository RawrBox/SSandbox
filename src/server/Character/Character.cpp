/*
 * Copyright (C) 2020 SSandbox project (https://github.com/SSandbox)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */

#include "PCH.h"
#include "Character.h"
#include "PlayerSession.h"

namespace Game
{

std::atomic<uint64> gIDCounter = 0;

Character::Character() : Object({ ObjectGuid::HighGuid::Player, gIDCounter++}, ObjectType::Player), _position(241.612411f, -2999.420166f, 1514.297363f), _session(nullptr), _flightSpeed(1.f)
{
    std::fill(_equipedItems.begin(), _equipedItems.end(), 0);
}

void Character::SetActiveSession(Player::Session* session)
{
    _session = session;
}

void Character::Logout()
{
    Packet logoutComplete(Opcode::SMSG_LOGOUT_COMPLETE);
    _session->SendPacket(logoutComplete);
    _session->_currentCharacter = nullptr;
    _session = nullptr;
}

void Character::ReadCreationFromBuffer(Buffer const& buffer)
{
    auto length = buffer.ReadBits<6>();
    auto hasTemplateSet = buffer.ReadBits<1>();
    uint32 characterOptionsCount;

    buffer.ReadBits<1>(); // IsTrialBoost
    buffer.ReadBits<1>(); // UseNPE

    buffer >> _race;
    buffer >> _class;
    buffer >> _sex;
    buffer >> characterOptionsCount;
    _name = buffer.ReadString(length);

    if (hasTemplateSet)
        buffer.ReadSkip<uint32>();

    _customizationOptions.resize(characterOptionsCount);
    for (auto& option : _customizationOptions)
        buffer >> option;
}

void Character::FinishCreatingCharacter()
{
    _level = Globals::MaxLevel;
    _mapID = 2444;
    _orientation = 0;

    for (auto itemID : DataStores::GetItemsForCharacterLoadout(_race, _class, 9))
    {
        auto slot = GetEquipmentSlotForItem(itemID);

        if (slot != EquipmentSlot::None)
            _equipedItems[Utils::ToUnderlying(slot)] = itemID;
    }

    if (!DataStores::ChrRaces[_race]->Alliance)
    {
        _knownSpells.emplace_back(668); // Common - Alliance
        _skills[0].SkillLineID = 98;    // Common language
    }
    else
    {
        _knownSpells.emplace_back(669); // Orcish - Horde
        _skills[0].SkillLineID = 109;   // Orcish language
    }

    _skills[0].SkillRank = 1;
    _skills[0].SkillMaxRank = 1;
    _skills[0].SkillStep = 1;
}

void Character::FinishLoggingIn()
{
    uint32 tutorialFlags[8] = { 0xFFF797BB, 0x1EE58DFF, 0, 0, 0, 0, 0, 0 };
    Packet tutorialFlagsPacket(Opcode::SMSG_TUTORIAL_FLAGS);
    tutorialFlagsPacket.WriteBytes(tutorialFlags, 8);
    _session->SendPacket(tutorialFlagsPacket);

    Packet talentData(Opcode::SMSG_UPDATE_TALENT_DATA);
    talentData << uint8(0);
    talentData << uint32(0); // Spec
    talentData << uint32(1);

    talentData << uint32(0);
    talentData << uint32(0);
    talentData << uint32(0);
    _session->SendPacket(talentData);

    Packet knownSpells(Opcode::SMSG_SEND_KNOWN_SPELLS);
    knownSpells.WriteBits<1>(true); // IsLoading
    knownSpells << uint32(_knownSpells.size());
    knownSpells << uint32(0);

    for (auto spellID : _knownSpells)
        knownSpells << uint32(spellID);

    _session->SendPacket(knownSpells);

    Packet actionButtons(Opcode::SMSG_UPDATE_ACTION_BUTTONS);

    for (int i = 0; i < 132; ++i)
        actionButtons << uint64(0);

    actionButtons << uint8(0);
    _session->SendPacket(actionButtons);

    Packet accountDataTimes(Opcode::SMSG_ACCOUNT_DATA_TIMES);
    accountDataTimes << GetGUID();
    accountDataTimes << time(nullptr);

    for (int i = 0; i < 15; ++i)
        accountDataTimes << int64((i == 0 || i == 4) ? time(nullptr) : 0);

    _session->SendPacket(accountDataTimes);

    _session->SendUpdateObject();
    SetCanFly(true);
    SendMessage("Welcome to SSandbox!");
}

void Character::Teleport(uint16 mapID, Position pos)
{
    bool isTeleportingFar = mapID != _mapID;

    if (isTeleportingFar)
    {
        Packet transferPending(Opcode::SMSG_TRANSFER_PENDING);
        transferPending << int32(mapID);
        transferPending << _position;
        transferPending.WriteBits<1>(0);
        transferPending.WriteBits<1>(0);
        transferPending.FlushBits();
        _session->SendPacket(transferPending);


        Packet suspendToken(Opcode::SMSG_SUSPEND_TOKEN);
        suspendToken << uint32(0);      // SeqIdx
        suspendToken.WriteBits<2>(1);   // Not seamless
        suspendToken.FlushBits();
        _session->SendPacket(suspendToken);

        _mapID = mapID;
        _position = pos;
    }
    else
    {
        _position = pos;

        Packet moveTeleport(Opcode::SMSG_MOVE_TELEPORT);
        moveTeleport << GetGUID();
        moveTeleport << uint32(0);  // SeqIdx
        moveTeleport << pos;
        moveTeleport << float(_orientation);
        moveTeleport << uint8(0);
        moveTeleport.WriteBits<1>(0);
        moveTeleport.WriteBits<1>(0);
        moveTeleport.FlushBits();
        _session->SendPacket(moveTeleport);
    }

}

void Character::WriteEnumCharacter(Buffer& buffer, uint8 index) const
{
    buffer << GetGUID();
    buffer << uint64(0);    // GuidClubMember
    buffer << uint8(index);
    buffer << uint8(_race);
    buffer << uint8(_class);
    buffer << uint8(_sex);
    buffer << uint32(_customizationOptions.size());
    buffer << uint8(_level);
    buffer << int32(0);    // Zone
    buffer << int32(_mapID);
    buffer << _position;
    buffer << ObjectGuid(); // Guild
    buffer << uint32(0);    // Flags
    buffer << uint32(0);    // Flags2
    buffer << uint32(0);    // Flags3
    buffer << uint32(0);    // PetInfo
    buffer << uint32(0);    // PetInfo
    buffer << uint32(0);    // PetInfo

    buffer << uint32(0);    // Professions
    buffer << uint32(0);    // Professions

    for (auto equipedItemID : _equipedItems)
    {
        auto itemModifiedAppearance =  DataStores::GetItemModifiedAppearanceByItemID(equipedItemID);
        auto itemEntry = DataStores::Item[equipedItemID];

        buffer << uint32(itemModifiedAppearance ? DataStores::ItemAppearence[itemModifiedAppearance->ItemAppearanceID]->ItemDisplayInfoID : 0);
        buffer << uint32(0);    // Enchant
        buffer << int32(0);
        buffer << uint8(itemEntry ? itemEntry->InventoryType : 0);
        buffer << uint8(itemEntry ? itemEntry->SubclassID : 0);
    }

    buffer << int64(0);
    buffer << uint16(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);

    for (auto const& options : _customizationOptions)
        buffer << options;

    buffer.WriteBits<6>(_name.length());
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<5>(0);

    buffer.FlushBits();
    buffer.WriteString(_name);
}

void Character::WriteMovementCreateBlock(Buffer& buffer) const
{
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(1);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(1);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(1);
    buffer.WriteBits<1>(0);
    buffer.FlushBits();

    buffer << GetGUID();
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << _position;
    buffer << float(_orientation);

    buffer << float(0.f);
    buffer << float(0.f);

    buffer << uint32(0);
    buffer << uint32(0);

    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);

    buffer << float(7.f);
    buffer << float(7.f);
    buffer << float(7.f);
    buffer << float(7.f);
    buffer << float(7.f);
    buffer << float(150.f);
    buffer << float(7.f);
    buffer << float(7.f);
    buffer << float(7.f);

    buffer << uint32(0);
    buffer << float(1.0f);
    buffer << float(0.f);
    buffer << float(0.f);
    buffer << float(0.f);
    buffer << float(0.f);
    buffer << float(0.f);
    buffer << float(0.f);

    buffer.WriteBits<1>(0);
    buffer.FlushBits();

    buffer << uint32(0);

    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.FlushBits();
}

void Character::WriteUpdateFieldsCreateBlock(Buffer& buffer) const
{
    Object::WriteUpdateFieldsCreateBlock(buffer);
    WriteUnitData(buffer);
    WritePlayerData(buffer);
    WriteActivePlayerData(buffer);
}

void Character::WriteUnitData(Buffer& buffer) const
{
    buffer << int32(GetNativeDisplayID());  // DisplayId
    for (std::size_t i = 0; i < 2; ++i)
        buffer << uint32(0);                // NpcFlags

    buffer << uint32(0);                    // StateSpellVisualId
    buffer << uint32(0);                    // StateAnimId
    buffer << uint32(0);                    // StateAnimKitId
    buffer << uint32(0);                    // StateWorldEffectIdSize
    buffer << uint32(0);                    // StateWorldEffectsQuestObjectiveId
    buffer << int32(0);                     // SpellOverrideNameId

    buffer << ObjectGuid();                 // Charm
    buffer << ObjectGuid();                 // Summon
    buffer << ObjectGuid();                 // Critter
    buffer << ObjectGuid();                 // CharmedBy
    buffer << ObjectGuid();                 // SummonedBy
    buffer << ObjectGuid();                 // CreatedBy
    buffer << ObjectGuid();                 // DemonCreator
    buffer << ObjectGuid();                 // LookAtControllerTarget
    buffer << ObjectGuid();                 // Target
    buffer << ObjectGuid();                 // BattlePetCompanionGuid
    buffer << uint64(0);                    // BattlePetDBId
    buffer << int32(0);                     // ChannelData - SpellId
    buffer << int32(0);                     // ChannelData - SpellXSpellVisualId
    buffer << int32(0);                     // ChannelData - ScriptVisualId
    buffer << int8(0);                      // Unknown
    buffer << uint32(0);                    // SummonedByHomeRealm
    buffer << uint8(_race);                 // Race
    buffer << uint8(_class);                // Class
    buffer << uint8(_class);                // PlayerClassId
    buffer << uint8(_sex);                  // Sex
    buffer << uint8(0);                     // DisplayPower
    buffer << uint32(0);                    // OverrideDisplayPower
    buffer << int64(1);                     // Health

    for (std::size_t i = 0; i < 7; ++i)
    {
        buffer << int32(0);                 // Power
        buffer << int32(0);                 // MaxPower
    }

    for (std::size_t i = 0; i < 7; ++i)
    {
        buffer << float(1.f);               // PowerRegenFlatModifier
        buffer << float(1.f);               // PowerRegenInterruptedFlatModifier
    }

    buffer << int64(1);                     // MaxHealth
    buffer << int32(_level);                // Level
    buffer << int32(_level);                // EffectiveLevel
    buffer << int32(0);                     // ContentTuningId
    buffer << int32(0);                     // ScalingLevelMin
    buffer << int32(0);                     // ScalingLevelMax
    buffer << int32(0);                     // ScalingLevelDelta
    buffer << int32(0);                     // ScalingFactionGroup
    buffer << int32(0);                     // ScalingHealthItemLevelCurveId
    buffer << int32(0);                     // ScalingDamageItemLevelCurveId
    buffer << int32(35);                    // Faction

    for (std::size_t i = 0; i < 3; ++i)
    {
        buffer << int32(0);                 // VirtualItem - ItemId
        buffer << int32(0);                 // VirtualItem - SecondaryItemModifiedAppearanceId
        buffer << uint16(0);                // VirtualItem - ItemAppearanceId
        buffer << uint16(0);                // VirtualItem - ItemVisual
    }

    buffer << uint32(0);                    // Flags
    buffer << uint32(0);                    // Flags2
    buffer << uint32(0);                    // Flags3
    buffer << uint32(0);                    // AuraState

    for (std::size_t i = 0; i < 2; ++i)
    {
        buffer << uint32(0);                // AttackRoundBaseTime
    }

    buffer << uint32(1);                    // RangedAttackRoundBaseTime
    buffer << float(1);                     // BoundingRadius
    buffer << float(1);                     // CombatReach
    buffer << float(1);                     // DisplayScale
    buffer << int32(0);                     // CreatureFamily
    buffer << int32(0);                     // CreatureType
    buffer << int32(GetNativeDisplayID());  // NativeDisplayId
    buffer << float(1);                     // NativeXDisplayScale
    buffer << int32(0);                     // MountDisplayId
    buffer << int32(0);                     // CosmeticMountDisplayId

    buffer << float(1);                     // MinDamage
    buffer << float(1);                     // MaxDamage
    buffer << float(1);                     // MinOffhandDamage
    buffer << float(1);                     // MaxOffhandDamage

    buffer << uint8(0);                     // StandState
    buffer << uint8(0);                     // PetTalentPoints
    buffer << uint8(0);                     // VisFlags
    buffer << uint8(0);                     // AnimTier
    buffer << uint32(0);                    // PetNumber
    buffer << uint32(0);                    // PetNameTimestamp
    buffer << uint32(0);                    // PetExperience
    buffer << uint32(0);                    // PetNextLevelExperience
    buffer << float(1);                     // ModCastingSpeed
    buffer << float(1);                     // ModCastingSpeedNeg
    buffer << float(1);                     // ModSpellHaste
    buffer << float(1);                     // ModHaste
    buffer << float(1);                     // ModRangedHaste
    buffer << float(1);                     // ModHasteRegen
    buffer << float(1);                     // ModTimeRate
    buffer << int32(0);                     // CreatedBySpell
    buffer << int32(0);                     // EmoteState

    for (std::size_t i = 0; i < 4; ++i)
    {
        buffer << int32(0);                 // Stats
        buffer << int32(0);                 // StatPosBuff
        buffer << int32(0);                 // StatNegBuff
    }

    for (std::size_t i = 0; i < 7; ++i)
    {
        buffer << int32(0);                 // Resistances
    }

    for (std::size_t i = 0; i < 7; ++i)
    {
        buffer << int32(0);                 // BonusResistanceMods
        buffer << int32(0);                 // ManaCostModifier
    }

    buffer << int32(1);                     // BaseMana
    buffer << int32(1);                     // BaseHealth

    buffer << uint8(0);                     // SheatheState
    buffer << uint8(1);                     // PvpFlags
    buffer << uint8(0);                     // PetFlags
    buffer << uint8(0);                     // ShapeshiftForm

    buffer << int32(0);                     // AttackPower
    buffer << int32(0);                     // AttackPowerModPos
    buffer << int32(0);                     // AttackPowerModNeg
    buffer << float(1);                     // AttackPowerMultiplier
    buffer << int32(0);                     // RangedAttackPower
    buffer << int32(0);                     // RangedAttackPowerModPos
    buffer << int32(0);                     // RangedAttackPowerModNeg
    buffer << float(1);                     // RangedAttackPowerMultipler
    buffer << int32(0);                     // MainhandWeaponAttackPower
    buffer << int32(0);                     // OffhandWeaponAttackPower
    buffer << int32(0);                     // RangedWeaponAttackPower
    buffer << int32(0);                     // SetAttackSpeedAura
    buffer << float(0);                     // Lifesteal
    buffer << float(0);                     // MinRangedDamage
    buffer << float(0);                     // MaxRangedDamage
    buffer << float(1);                     // ManaCostMultiplier
    buffer << float(1);                     // MaxHealthModifier

    buffer << float(0);                     // HoverHeight
    buffer << int32(0);                     // MinItemLevelCutoff
    buffer << int32(0);                     // MinItemLevel
    buffer << int32(0);                     // MaxItemLevel
    buffer << int32(0);                     // AzeriteItemLevel
    buffer << int32(0);                     // WildBattlePetLevel
    buffer << int32(0);                     // BattlePetCompanionExperience
    buffer << uint32(0);                    // BattlePetCompanionNameTimestamp
    buffer << int32(0);                     // InteractSpellId
    buffer << int32(0);                     // ScaleDuration
    buffer << int32(0);                     // LooksLikeMountId
    buffer << int32(0);                     // LooksLikeCreatureId
    buffer << int32(0);                     // LookAtControllerId
    buffer << int32(0);                     // TaxiNodesId
    buffer << ObjectGuid();                 // GuildGuid
    buffer << uint32(0);                    // PassiveSpells.size()
    buffer << uint32(0);                    // WorldEffects.size()
    buffer << uint32(0);                    // ChannelObjects.size()
    buffer << uint32(0);                    // SilencedSchoolMask;
    buffer << ObjectGuid();                 // NameplateAttachToGUID
}

void Character::WritePlayerData(Buffer& buffer) const
{
    buffer << ObjectGuid();                 // DuelArbiter
    buffer << ObjectGuid();                 // WowAccount
    buffer << ObjectGuid();                 // LootTargetGuid
    buffer << uint32(0);                    // PlayerFlags
    buffer << uint32(0);                    // PlayerFlagsEx
    buffer << uint32(0);                    // GuildRankId
    buffer << uint32(0);                    // GuildDeleteDate
    buffer << int32(0);                     // GuildLevel
    buffer << uint32(_customizationOptions.size());
    buffer << uint8(0);                     // PartyType
    buffer << uint8(_sex);                  // NativeSex
    buffer << uint8(0);                     // Inebriation
    buffer << uint8(0);                     // PvpTitle
    buffer << uint8(0);                     // ArenaFaction
    buffer << uint32(0);                    // DuelTeam
    buffer << int32(0);                     // GuildTimeStamp

    for (std::size_t i = 0; i < 125; ++i)
    {
        buffer << int32(0);                 // QuestID
        buffer << uint32(0);                // StateFlags
        buffer << uint32(0);                // EndTime
        buffer << uint32(0);                // AcceptTime
        buffer << uint32(0);                // ObjectiveFlags
        for (std::size_t j = 0; j < 24; ++j)
        {
            buffer << int16(0);             // ObjectiveProgress
        }
    }

    buffer << uint32(0);                    // QuestSessionQuestLog.size()

    for (std::size_t i = 0; i < 19; ++i)
    {
        buffer << uint32(_equipedItems[i]);    // VisibleItem - ItemId
        buffer << int32(0);                    // VisibleItem - SecondaryItemModifiedAppearanceId

        uint16 itemAppearanceModId = 0;
        if (auto itemModfiedAppearanceEntry = DataStores::GetItemModifiedAppearanceByItemID(_equipedItems[i]))
            itemAppearanceModId = uint16(_equipedItems[i] ? itemModfiedAppearanceEntry->ItemAppearanceModifierID : 0);

        buffer << uint16(itemAppearanceModId); // VisibleItem - ItemAppearanceModId
        buffer << uint16(0);                   // VisibleItem - ItemVisual
    }

    buffer << int32(672);                   // PlayerTitle
    buffer << int32(0);                     // FakeInebriation
    buffer << uint32(0);                    // VirtualPlayerRealm
    buffer << uint32(0);                    // CurrentSpecId
    buffer << int32(0);                     // TaxiMountAnimKitId

    for (std::size_t i = 0; i < 6; ++i)
    {
        buffer << float(0);                 // AvgItemLevel
    }

    buffer << uint8(0);                     // CurrentBattlePetBreedQuality
    buffer << int32(0);                     // HonorLevel
    buffer << uint32(0);                    // ArenaCooldowns.size()
    buffer << int32(0);                     // Field_B0
    buffer << int32(0);                     // Field_B4

    buffer << uint32(0);                    // CtrOptions - ContentTuningConditionMask
    buffer << int32(0);                     // CtrOptions - Field_4
    buffer << uint32(0);                    // CtrOptions - ExpansionLevelMask

    buffer << int32(0);                     // CovenantID
    buffer << int32(0);                     // SoulbindID

    for (auto const& options : _customizationOptions)
        buffer << options;

    buffer.WriteBits<1>(0);                 // HasQuestSession
    buffer.WriteBits<1>(0);                 // HasLevelLink
    buffer.FlushBits();

    buffer << float(0.0f);                  // DungeonScore - CurrentSeasonScore
    buffer << float(0.0f);                  // DungeonScore - LifetimeBestSeasonScore
    buffer << uint32(0);                    // DungeonScore - Runs
}

void Character::WriteActivePlayerData(Buffer& buffer) const
{
    for (std::size_t i = 0; i < 218; ++i)
    {
        buffer << ObjectGuid();             // InvSlots
    }
    buffer << ObjectGuid();                 // FarsightObject
    buffer << ObjectGuid();                 // SummonedBattlePetGuid
    buffer << uint32(0);                    // KnownTitles
    buffer << int64(99999999999);           // Coinage
    buffer << int32(0);                     // XP
    buffer << int32(0);                     // NextLevelXP
    buffer << int32(0);                     // TrialXP

    for (auto const& skill : _skills)
    {
        buffer << uint16(skill.SkillLineID);
        buffer << uint16(skill.SkillStep);
        buffer << uint16(skill.SkillRank);
        buffer << uint16(skill.SkillStartingRank);
        buffer << uint16(skill.SkillMaxRank);
        buffer << int16(skill.SkillTempBonus);
        buffer << uint16(skill.SkillPermBonus);
    }

    buffer << int32(0);                     // CharacterPoints
    buffer << int32(7);                     // MaxTalentTiers
    buffer << uint32(0);                    // TrackCreatureMask
    buffer << float(0);                     // MainhandExpertise
    buffer << float(0);                     // OffhandExpertise
    buffer << float(0);                     // RangedExpertise
    buffer << float(0);                     // CombatRatingExpertise
    buffer << float(0);                     // BlockPercentage
    buffer << float(0);                     // DodgePercentage
    buffer << float(0);                     // DodgePercentageFromAttribute
    buffer << float(0);                     // ParryPercentage
    buffer << float(0);                     // ParryPercentageFromAttribute
    buffer << float(0);                     // CritPercentage
    buffer << float(0);                     // RangedCritPercentage
    buffer << float(0);                     // OffhandCritPercentage
    buffer << float(0);                     // SpellCritPercentage
    buffer << int32(0);                     // ShieldBlock
    buffer << float(0);                     // ShieldBlockCritPercentage
    buffer << float(0);                     // Mastery
    buffer << float(0);                     // Speed
    buffer << float(0);                     // Avoidance
    buffer << float(0);                     // Sturdiness
    buffer << int32(0);                     // Versatility
    buffer << float(0);                     // VersatilityBonus
    buffer << float(0);                     // PvpPowerDamage
    buffer << float(0);                     // PvpPowerHealing

    for (std::size_t i = 0; i < 240; ++i)
    {
        buffer << uint64(std::numeric_limits<uint64>::max); // ExploredZones
    }

    for (std::size_t i = 0; i < 2; ++i)
    {
        buffer << uint32(0);                // Threshold
        buffer << uint8(0);                 // StateId
    }

    for (std::size_t i = 0; i < 7; ++i)
    {
        buffer << int32(0);                 // ModDamageDonePos
        buffer << int32(0);                 // ModDamageDoneNeg
        buffer << float(1);                 // ModDamageDonePercent
        buffer << float(1);                 // ModHealingDonePercent
    }

    buffer << int32(0);                     // ModHealingDonePos
    buffer << float(1);                     // ModHealingPercent
    buffer << float(1);                     // ModPeriodicHealingDonePercent

    for (std::size_t i = 0; i < 3; ++i)
    {
        buffer << float(1);                 // WeaponDmgMultipliers
        buffer << float(1);                 // WeaponAttackSpeedMultipliers
    }

    buffer << float(1);                     // ModSpellPowerPercent
    buffer << float(1);                     // ModResiliencePercent
    buffer << float(0);                     // OverrideSpellPowerByAPPercent
    buffer << float(0);                     // OverrideApBySpellPowerPercent
    buffer << int32(0);                     // ModTargetResistance
    buffer << int32(0);                     // ModTargetPhysicalResistance
    buffer << uint32(0);                    // LocalFlags
    buffer << uint8(0);                     // GrantableLevels
    buffer << uint8(0);                     // MultiActionBars
    buffer << uint8(0);                     // LifetimeMaxRank
    buffer << uint8(0);                     // NumRespecs
    buffer << uint32(0);                    // PvpMedals

    for (std::size_t i = 0; i < 12; ++i)
    {
        buffer << uint32(0);                // BuybackPrice
        buffer << uint64(0);                // BuybackTimestamp
    }

    buffer << uint16(0);                    // TodayHonorableKills
    buffer << uint16(0);                    // YesterdayHonorableKills
    buffer << uint32(0);                    // LifetimeHonorableKills
    buffer << int32(0);                     // WatchedFactionIndex

    for (std::size_t i = 0; i < 32; ++i)
    {
        buffer << int32(0);                 // CombatRatings
    }

    buffer << int32(60);                    // MaxLevel
    buffer << int32(0);                     // ScalingPlayerLevelDelta
    buffer << int32(0);                     // MaxCreatureScalingLevel

    for (std::size_t i = 0; i < 4; ++i)
    {
        buffer << uint32(0);                // NoReagentCostMask
    }

    buffer << int32(0);                     // PetSpellPower

    for (std::size_t i = 0; i < 2; ++i)
    {
        buffer << int32(0);                 // ProfessionSkillLine
    }

    buffer << float(1);                     // UiHitModifier
    buffer << float(1);                     // UiSpellHitModifier
    buffer << int32(0);                     // HomeRealmTimeOffset
    buffer << float(0);                     // ModPetHaste
    buffer << int8(0);                      // JailersTowerLevelMax;
    buffer << int8(0);                      // JailersTowerLevel
    buffer << uint8(0);                     // LocalRegenFlags
    buffer << uint8(0);                     // AuraVision
    buffer << uint8(24);                    // NumBackpackSlots
    buffer << int32(0);                     // OverrideSpellsId
    buffer << uint16(0);                    // LootSpecId
    buffer << uint32(0);                    // OverrideZonePvpType
    buffer << ObjectGuid();                 // BnetAccount
    buffer << uint64(0);                    // GuildClubMemberID

    for (std::size_t i = 0; i < 4; ++i)
    {
        buffer << uint32(0);                // BagSlotFlags
    }
    for (std::size_t i = 0; i < 7; ++i)
    {
        buffer << uint32(0);                // BankBagSlotFlags
    }
    for (std::size_t i = 0; i < 875; ++i)
    {
        buffer << uint64(0);                // QuestCompleted
    }

    buffer << int32(0);                     // Honor
    buffer << int32(0);                     // HonorNextLevel
    buffer << uint8(5);                     // NumBankSlots

    buffer << uint32(0);                    // ResearchSites.size()
    buffer << uint32(0);                    // ResearchSiteProgress.size()
    buffer << uint32(0);                    // DailyQuestsCompleted.size()
    buffer << uint32(0);                    // AvailableQuestLineXQuestIDs.size()
    buffer << uint32(0);                    // Heirlooms.size()
    buffer << uint32(0);                    // HeirloomFlags.size()
    buffer << uint32(0);                    // Toys.size()
    buffer << uint32(0);                    // ToyFlags.size()
    buffer << uint32(0);                    // Transmog.size()
    buffer << uint32(0);                    // ConditionalTransmog.size()
    buffer << uint32(0);                    // SelfResSpells.size()
    buffer << uint32(0);                    // RuneforgePowers.size()
    buffer << uint32(0);                    // TransmogIllusions.size()
    buffer << uint32(0);                    // CharacterRestrictions.size()
    buffer << uint32(0);                    // SpellPctModByLabel.size()
    buffer << uint32(0);                    // SpellFlatModByLabel.size()
    buffer << uint32(0);                    // Research.size()
    buffer << uint32(0);                    // MawPowers.size()
    buffer << uint32(0);                    // MultiFloorExploration.size()
    buffer << uint32(0);                    // RecipeProgression.size()
    buffer << uint32(0);                    // ReplayedQuests.size()
    buffer << uint32(0);                    // DisabledSpells.size()

    buffer << int32(0);                     // UiChromieTimeExpansionId
    buffer << int32(0);                     // TransportServerTime
    buffer << uint32(0);                    // WeeklyRewardsPeriodSinceOrigin
    buffer << int16(0);                     // DEBUGSoulbindConduitRank
    buffer << int32(0);                     // Unknown

    for (std::size_t i = 0; i < 6; ++i)
    {
        buffer << uint32(0);                // PvpInfo - WeeklyPlayed
        buffer << uint32(0);                // PvpInfo - WeeklyWon
        buffer << uint32(0);                // PvpInfo - SeasonPlayed
        buffer << uint32(0);                // PvpInfo - SeasonWon
        buffer << uint32(0);                // PvpInfo - Rating
        buffer << uint32(0);                // PvpInfo - WeeklyBestRating
        buffer << uint32(0);                // PvpInfo - SeasonBestRating
        buffer << uint32(0);                // PvpInfo - PvpTierID
        buffer << uint32(0);                // PvpInfo - WeeklyBestWinPvpTierID
        buffer << uint32(0);                // PvpInfo - Field_28
        buffer << uint32(0);                // PvpInfo - Field_2C

        buffer.WriteBits<1>(0);             // PvpInfo - Disqualified
        buffer.FlushBits();
    }

    buffer.WriteBits<1>(0);                 // BackpackAutoSortDisabled
    buffer.WriteBits<1>(0);                 // BankAutoSortDisabled
    buffer.WriteBits<1>(0);                 // SortBagsRightToLeft
    buffer.WriteBits<1>(0);                 // InsertItemsLeftToRight
    buffer.WriteBits<1>(0);                 // QuestSession
    buffer.FlushBits();

    buffer << ObjectGuid();                 // Field_1410 - Field_0
    buffer << int32(0);                     // Field 1410 - Field_10

    buffer << uint32(0);                    // Traits - TraitConfigs.size()

    buffer << uint32(0);                    // DungeonScore - Seasons.size()
    buffer << int32(0);                     // DungeonScore - TotalRuns
}

void Character::SetCanFly(bool value)
{
    Packet packet(value ? Opcode::SMSG_MOVE_SET_CAN_FLY : Opcode::SMSG_MOVE_UNSET_CAN_FLY);
    packet << GetGUID();
    packet << uint32(0);    // SeqIdx
    _session->SendPacket(packet);
}

void Character::SendMessage(std::string_view message)
{
    if (!_session)
        return;

    Packet packet(Opcode::SMSG_CHAT);

    packet << uint8(0);
    packet << uint32(0);
    packet << ObjectGuid();
    packet << ObjectGuid();
    packet << ObjectGuid();
    packet << ObjectGuid();
    packet << uint32(33619968); // VirtualRealmID
    packet << uint32(33619968); // VirtualRealmID
    packet << ObjectGuid();
    packet << uint32(0);
    packet << float(0.f);
    packet.WriteBits<11>(0);
    packet.WriteBits<11>(0);
    packet.WriteBits<5>(0);
    packet.WriteBits<7>(0);
    packet.WriteBits<12>(message.size());
    packet.WriteBits<14>(0);
    packet.WriteBits<1>(0);
    packet.WriteBits<1>(0);
    packet.WriteBits<1>(0);
    packet.WriteBits<1>(0);
    packet.FlushBits();

    packet.WriteString(message);
    _session->SendPacket(packet);
}

uint16 Character::GetMapID() const
{
    return _mapID;
}

Position Character::GetPosition() const
{
    return _position;
}

float Character::GetOrientation() const
{
    return _orientation;
}

uint32 Character::GetNativeDisplayID() const
{
    return DataStores::GetDisplayIDForRace(_race, _sex);
}

EquipmentSlot Character::GetEquipmentSlotForItem(uint32 itemID) const
{
    auto itemEntry = DataStores::Item[itemID];

    if (!itemEntry)
        return EquipmentSlot::None;

    switch (Utils::ToEnum<InventoryType>(itemEntry->InventoryType))
    {
    case Head:
        return EquipmentSlot::Head;
    case Neck:
        return EquipmentSlot::Neck;
    case Shoulds:
        return EquipmentSlot::Shoulders;
    case Body:
        return EquipmentSlot::Body;
    case Robe:
    case Chest:
        return EquipmentSlot::Chest;
    case Waist:
        return EquipmentSlot::Waist;
    case Legs:
        return EquipmentSlot::Legs;
    case Feet:
        return EquipmentSlot::Feet;
    case Wrist:
        return EquipmentSlot::Wrist;
    case Hands:
        return EquipmentSlot::Hands;
    case Finger:
        return _equipedItems[Utils::ToUnderlying(EquipmentSlot::Finger1)] ? EquipmentSlot::Finger2 : EquipmentSlot::Finger1;
    case Trinket:
        return _equipedItems[Utils::ToUnderlying(EquipmentSlot::Trinket1)] ? EquipmentSlot::Trinket2 : EquipmentSlot::Trinket1;
    case Weapon:
        return _equipedItems[Utils::ToUnderlying(EquipmentSlot::MainHand)] ? EquipmentSlot::OffHand : EquipmentSlot::MainHand;
    case Shield:
        return EquipmentSlot::OffHand;
    case Ranged:
        return EquipmentSlot::MainHand;
    case Cloak:
        return EquipmentSlot::Back;
    case TwoHandedWeapon:
        return EquipmentSlot::MainHand;
    case Tabard:
        return EquipmentSlot::Tabard;
    case MainHandWeapon:
        return EquipmentSlot::MainHand;
    case OffHandWeapon:
        return EquipmentSlot::OffHand;
    default:
        return EquipmentSlot::None;
    }
}

Buffer& operator<<(Buffer& lhs, Character::CustomizationOption const& rhs)
{
    lhs << rhs.OptionID;
    lhs << rhs.Value;
    return lhs;
}

Buffer const& operator>>(Buffer const& lhs, Character::CustomizationOption& rhs)
{
    lhs >> rhs.OptionID;
    lhs >> rhs.Value;
    return lhs;
}
} // Game

