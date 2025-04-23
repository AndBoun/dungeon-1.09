//
// Created By Andrew Boun on 4/16/2025
//

#include <dungeon/Dungeon.hpp>
#include <ui/ui.hpp>

bool Dungeon::pickUpItem(PC &character){

    int itemID = getItemID(character.getPosition());

    if (itemID == -1) {
        return false; // No item at the character's position
    }

    if (character.symbol == PLAYER){



        if (!addToEquipment(character, itemID) && character.items.size() < 10) {
            character.items.push_back(items[itemID]);
        }
        else {
            return false; // Inventory is full
        }

        items[itemID]->pos = Point(-1, -1); // Remove item from the dungeon
        items[itemID]->inInventory = true; // Mark item as in inventory 
    
        if (items[itemID]->art) {
            itemDescList[items[itemID]->descID].canBeGenerated = false;
        }
    
        ui::render_top_bar(
            COLOR_SUCCESS_ID,
            "Picked up a %s: %c",
            items[itemID]->type.c_str(),
            items[itemID]->symbol
        );
    }
    

    return true;
}

bool Dungeon::addToEquipment(PC &character, int itemID){
    if (character.symbol != PLAYER) return false;

    std::string type = items[itemID]->type;

    if (type == WEAPON) {
        character.weapon_slot = items[itemID];
    }
    else if (type == OFFHAND) {
        character.offhand_slot = items[itemID];
    }
    else if (type == RANGED) {
        character.range_slot = items[itemID];
    }
    else if (type == ARMOR) {
        character.armor_slot = items[itemID];
    }
    else if (type == HELMET) {
        character.helmet_slot = items[itemID];
    }
    else if (type == CLOAK) {
        character.cloak_slot = items[itemID];
    }
    else if (type == GLOVES) {
        character.gloves_slot = items[itemID];
    }
    else if (type == BOOTS) {
        character.boots_slot = items[itemID];
    }
    else if (type == AMULET) {
        character.amulet_slot = items[itemID];
    }
    else if (type == RING) {
        if (!character.ring_slot_1) {
            character.ring_slot_1 = items[itemID];
        }
        else if (!character.ring_slot_2) {
            character.ring_slot_2 = items[itemID];
        }
        else {
            return false; // No available ring slots
        }
    } 
    else {
        return false;
    }

    items[itemID]->inInventory = true; // Mark item as in inventory
    return true;
}