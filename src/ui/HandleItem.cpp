//
// Created By Andrew Boun on 4/22/2025
//

#include <ui/ui.hpp>

void ui::expunge_item(Dungeon &d){

    Item *item = get_item_from_inventory(d);
    if (item == nullptr){ return; }


    item->inInventory = false;
    item->pos = Point(-1, -1);

    int id = item->ID;
    
    // Remove item from inventory, let destructor handle deletion
    for (size_t i = 0; i < d.getPC().items.size(); i++){
        if (d.pc.items[i]->ID == id){
            d.getPC().items.erase(d.getPC().items.begin() + i);
            break;
        }
    }

    clear_top_bar();
    render_grid_default(d);
}

void ui::drop_item(Dungeon &d){
    Item *item = get_item_from_inventory(d);
    if (item == nullptr){ return; }

    item->inInventory = false;
    item->pos = d.getPC().getPosition();
    

    for (size_t i = 0; i < d.getPC().items.size(); i++){
        if (d.pc.items[i]->ID == item->ID){
            d.getPC().items.erase(d.getPC().items.begin() + i);
            break;
        }
    }

    

    clear_top_bar();
    render_grid_default(d);
}

void ui::wear_item(Dungeon &d){
    Item *item = get_item_from_inventory(d);
    if (item == nullptr){ return; }



    for (size_t i = 0; i < d.getPC().items.size(); i++){
        if (d.pc.items[i]->ID == item->ID){
            d.getPC().items.erase(d.getPC().items.begin() + i);
            break;
        }
    }

    clear_top_bar();
    render_grid_default(d);
}

void ui::take_off_item(Dungeon &d){
    Item *item = get_item_from_equipment(d);
    if (item == nullptr){ return; }

    d.pc.items.push_back(item);

    if (item->type == WEAPON) {
        d.getPC().weapon_slot = nullptr;
    } else if (item->type == OFFHAND) {
        d.getPC().offhand_slot = nullptr;
    } else if (item->type == RANGED) {
        d.getPC().range_slot = nullptr;
    } else if (item->type == ARMOR) {
        d.getPC().armor_slot = nullptr;
    } else if (item->type == HELMET) {
        d.getPC().helmet_slot = nullptr;
    } else if (item->type == CLOAK) {
        d.getPC().cloak_slot = nullptr;
    } else if (item->type == GLOVES) {
        d.getPC().gloves_slot = nullptr;
    } else if (item->type == BOOTS) {
        d.getPC().boots_slot = nullptr;
    } else if (item->type == AMULET) {
        d.getPC().amulet_slot = nullptr;
    } else if (item->type == LIGHT) {
        d.getPC().light_slot = nullptr;
    } else if (item->type == RING) {
        // Remove from both ring slots if present
        if (d.getPC().ring_slot_1->ID == item->ID) {
            d.getPC().ring_slot_1 = nullptr;
        } else if (d.getPC().ring_slot_2->ID == item->ID) {
            d.getPC().ring_slot_2 = nullptr;
        }
    }

    d.pc.updatePCAttributes();

    clear_top_bar();
    render_grid_default(d);
}