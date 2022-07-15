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
#include "DB2.h"

namespace DataStores
{
namespace Structures
{
struct CharacterLoadout
{
    static constexpr char Filename[] = "characterloadout.csv";
    static constexpr char Format[] = "luuuu";
    static constexpr char Arrays[] = { 1, 1, 1, 1, 1 };
    static constexpr const char* Names[] = { "Racemask", "ID", "ChrClassID", "Purpose", "Field_2_5_1_38043_004" };
    static constexpr std::size_t IndexField = 1;

    struct Structure
    {
        uint64 Racemask;
        uint32 ID;
        uint32 ChrClassID;
        uint32 Purpose;
        uint32 Field_2_5_1_38043_004;
    };
};

struct CharacterLoadoutItem
{
    static constexpr char Filename[] = "characterloadoutitem.csv";
    static constexpr char Format[] = "uuu";
    static constexpr char Arrays[] = { 1, 1, 1 };
    static constexpr const char* Names[] = { "ID", "CharacterLoadoutID", "ItemID" };
    static constexpr std::size_t IndexField = 0;

    struct Structure
    {
        uint32 ID;
        uint32 CharacterLoadoutID;
        uint32 ItemID;
    };
};

struct ChrModel
{
    static constexpr char Filename[] = "chrmodel.csv";
    static constexpr char Format[] = "uuu";
    static constexpr char Arrays[] = { 1, 1, 1 };
    static constexpr const char* Names[] = { "ID", "Sex", "DisplayID" };
    static constexpr std::size_t IndexField = 0;

    struct Structure
    {
        uint32 ID;
        uint32 Sex;
        uint32 DisplayID;
    };
};

struct ChrRaceXChrModel
{
    static constexpr char Filename[] = "chrracexchrmodel.csv";
    static constexpr char Format[] = "uuu";
    static constexpr char Arrays[] = { 1, 1, 1 };
    static constexpr const char* Names[] = { "ID", "ChrRacesID", "ChrModelID" };
    static constexpr std::size_t IndexField = 0;

    struct Structure
    {
        uint32 ID;
        uint32 ChrRacesID;
        uint32 ChrModelID;
    };
};

struct ChrRaces
{
    static constexpr char Filename[] = "chrraces.csv";
    static constexpr char Format[] = "uuu";
    static constexpr char Arrays[] = { 1, 1, 1 };
    static constexpr const char* Names[] = { "ID", "Alliance", "PlayableRaceBit" };
    static constexpr std::size_t IndexField = 0;

    struct Structure
    {
        uint32 ID;
        uint32 Alliance;
        uint32 PlayableRaceBit;
    };
};

struct Item
{
    static constexpr char Filename[] = "item.csv";
    static constexpr char Format[] = "uuu";
    static constexpr char Arrays[] = { 1, 1, 1 };
    static constexpr const char* Names[] = { "ID", "SubclassID", "InventoryType" };
    static constexpr std::size_t IndexField = 0;

    struct Structure
    {
        uint32 ID;
        uint32 SubclassID;
        uint32 InventoryType;
    };
};

struct ItemModifiedAppearence
{
    static constexpr char Filename[] = "itemmodifiedappearance.csv";
    static constexpr char Format[] = "uuuuu";
    static constexpr char Arrays[] = { 1, 1, 1, 1, 1 };
    static constexpr const char* Names[] = { "ID", "ItemID", "ItemAppearanceModifierID", "ItemAppearanceID", "OrderIndex" };
    static constexpr std::size_t IndexField = 0;

    struct Structure
    {
        uint32 ID;
        uint32 ItemID;
        uint32 ItemAppearanceModifierID;
        uint32 ItemAppearanceID;
        uint32 OrderIndex;
    };
};

struct ItemAppearence
{
    static constexpr char Filename[] = "itemappearance.csv";
    static constexpr char Format[] = "uu";
    static constexpr char Arrays[] = { 1, 1 };
    static constexpr const char* Names[] = { "ID", "ItemDisplayInfoID" };
    static constexpr std::size_t IndexField = 0;

    struct Structure
    {
        uint32 ID;
        uint32 ItemDisplayInfoID;
    };
};

} // Structures

inline DB2<Structures::CharacterLoadout> CharacterLoadout;
inline DB2<Structures::CharacterLoadoutItem> CharacterLoadoutItem;
inline DB2<Structures::ChrModel> ChrModel;
inline DB2<Structures::ChrRaceXChrModel> ChrRaceXChrModel;
inline DB2<Structures::ChrRaces> ChrRaces;
inline DB2<Structures::Item> Item;
inline DB2<Structures::ItemModifiedAppearence> ItemModifiedAppearence;
inline DB2<Structures::ItemAppearence> ItemAppearence;

void LoadAdditionalInfo();

std::vector<uint32> GetItemsForCharacterLoadout(uint32 raceID, uint32 classID, uint32 purpose);
Structures::ItemModifiedAppearence::Structure const* GetItemModifiedAppearanceByItemID(uint32 itemID, uint32 ItemAppearanceModifierID = 0);
uint32 GetDisplayIDForRace(uint32 raceID, uint32 sex);

inline void Init(fs::path folder)
{
    #define LoadDB2(x) if (!x.Load(folder)) { Log::Log(LogSeverity::Error, "Error loading %s", x.Filename); exit(1); };
    LoadDB2(CharacterLoadout);
    LoadDB2(CharacterLoadoutItem);
    LoadDB2(ChrModel)
    LoadDB2(ChrRaceXChrModel)
    LoadDB2(ChrRaces)
    LoadDB2(Item)
    LoadDB2(ItemModifiedAppearence)
    LoadDB2(ItemAppearence)

    LoadAdditionalInfo();
}
} // Datastores
