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

#pragma once
#include "PCH.h"
#include "DB2Files.h"

namespace DataStores
{
    std::unordered_map<uint32, std::vector<uint32>> CharacterLoadoutToCharacterLoadoutItem;
    std::unordered_map<uint32, std::map<uint32, Structures::ItemModifiedAppearence::Structure const*>> ItemIDToModifiedAppearance;
    std::unordered_map<uint32, std::array<uint32, 4>> ChrRaceToDisplayID;

    void LoadAdditionalInfo()
    {
        for (auto const& characterLoadoutItem : CharacterLoadoutItem)
        {
            CharacterLoadoutToCharacterLoadoutItem[characterLoadoutItem.CharacterLoadoutID].push_back(characterLoadoutItem.ItemID);
        }

        for (auto const& modifiedAppearence : ItemModifiedAppearence)
        {
            ItemIDToModifiedAppearance[modifiedAppearence.ItemID].emplace(modifiedAppearence.ItemAppearanceModifierID, &modifiedAppearence);
        }

        for (auto const& raceXModel : ChrRaceXChrModel)
        {
            auto chrModelEntry = ChrModel[raceXModel.ChrModelID];
            ChrRaceToDisplayID[raceXModel.ChrRacesID][chrModelEntry->Sex] = chrModelEntry->DisplayID;
        }
    }

    std::vector<uint32> GetItemsForCharacterLoadout(uint32 raceID, uint32 classID, uint32 purpose)
    {
        auto chrRacesEntry = ChrRaces[raceID];

        for (auto& characterLoadout : CharacterLoadout)
            if ((chrRacesEntry->PlayableRaceBit & characterLoadout.Racemask) != 0 && characterLoadout.ChrClassID == classID && characterLoadout.Purpose == purpose)
                return CharacterLoadoutToCharacterLoadoutItem[characterLoadout.ID];

        return std::vector<uint32>();
    }

    Structures::ItemModifiedAppearence::Structure const* GetItemModifiedAppearanceByItemID(uint32 itemID, uint32 ItemAppearanceModifierID)
    {
        auto iter = ItemIDToModifiedAppearance.find(itemID);
        if (iter == ItemIDToModifiedAppearance.end())
            return nullptr;

        auto subIter = iter->second.find(ItemAppearanceModifierID);
        return subIter != iter->second.end() ? subIter->second : nullptr;
    }

    uint32 GetDisplayIDForRace(uint32 raceID, uint32 sex)
    {
        auto iter = ChrRaceToDisplayID.find(raceID);
        if (iter == ChrRaceToDisplayID.end())
            return 0;

        return iter->second[sex] != 0 ? iter->second[sex] : iter->second[3];
    }
} // Datastores
