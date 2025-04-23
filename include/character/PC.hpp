//
// Created By Andrew Boun on 4/2/2025
//

#ifndef PC_HPP
#define PC_HPP
#include <character/Character.hpp>
#include <utils/Point.hpp>
#include <dungeon/base/Cell.hpp>

const int PC_SPEED = 10; // Speed of the player character

class PC : public Character
{
public:
    Item *weapon_slot = nullptr; 
    Item *offhand_slot = nullptr;
    Item *range_slot = nullptr;
    Item *armor_slot = nullptr;
    Item *helmet_slot = nullptr;
    Item *cloak_slot = nullptr;
    Item *gloves_slot = nullptr;
    Item *boots_slot = nullptr;
    Item *amulet_slot = nullptr;   
    Item *ring_slot_1 = nullptr;
    Item *ring_slot_2 = nullptr;


    PC();
    PC(Point position);
    ~PC();
};

#endif