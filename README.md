# How To Run The Project:

 Create a `.rlg327` folder in your home directory and move the `monster_desc.txt` and `object_desc.txt` file into it:
```bash
mkdir ~/.rlg327
```

Build the project:
```bash
make
```

## Running configurations
Run the project:
```bash
./dungeon --load --save --nummon <number>
```


# Main Files:
```plain
/
├── include/
│   ├── ui
│   │   └── ui.hpp
│   ├── character/
│   │   └── pc.hpp
│   └── dungeon/
│       └── Dungeon.hpp
├── src/
│   ├── character/
│   │   └── PC.cpp
│   ├── dungeon/
│   │   └── DungeonCombat.cpp
│   ├── movement/
│   │   ├── MonsterMovement.cpp
│   │   └── PlayerMovement.cpp
│   └── ui/
│       ├── HandleItem.cpp
│       ├── InspectMonster.cpp
│       ├── ItemSelection.cpp
│       ├── RenderItems.cpp
│       └── ScrollableList.cpp
└── main.cpp
```

# About the Project:

## Constraints:
- All files and inputs are assumed to be valid

## Additional Notes
- No optional features were added from 1.08
- If descriptions are not fully on the screen when inspecting items or monsters, scroll using up and down arrow
- 10 to 20 items are randomly generate per level
- Players keep their carry and equipment items between levels.
- Item features for the PC only include bonus speed and damage (as that was listed for 1.09). Other item features (dodge, light radius, etc.) are not implemented.
- Item pickup only works for the player. Move over items to pick them up.
- Item stacking isn't explicitly implemented, the game prevents objects from generating on top of each other, but if the player forcefully drops multiple items in the same spot, any of the symbols of that item may appear at that position, and you may pick up at an item at that position as many times as there is an item there.

## How the Project Runs:
In `main.cpp`, it creates a dungeon instance, `start_gameplay()` in `Dungeon.cpp`.  When it's a character's turn, `MonsterMovement.cpp` or `PlayerMovement.cpp` will be called. In `MonsterMovement.cpp`, monsters `displaceNPC()` instead of killing each other. When a Monster of Player attacks, they stay in place, and call `attackCharacter()` in `DungeonCombat.cpp`. When it's a player turn to move, in `ui.cpp`, they can use all the new controls.  `ScrollableList.cpp` is a helper function to render a scrollable list based on each string array, where each line is a entry in the array. `RenderItems.cpp` render the equipment and inventory. `ItemSelection.cpp` are helper functions for that allow the player to select a carry or equipment slot for the other functions. `InspectMonster.cpp` handles selecting and inspecting a monster. `HandleItem.cpp` deals with inspecting, expunging, dropping, wearing, and taking off items. You can only win the game by killing a BOSS now. Creating a dungeon without monsters means you can never win the game.


# Example Gameplay:

## Inventory and Monster Inspection:
![Inventory_and_Monster](https://github.com/user-attachments/assets/8acca72f-0ba7-45e3-b566-57d4489b9b0d)

## Player Attack:
![Player_Attack](https://github.com/user-attachments/assets/67a0bd0b-e42c-42b4-8917-6d3528cca52f)

## Monster Attack:
![Monster_Attack](https://github.com/user-attachments/assets/6a3ae09a-0ad3-4e01-968a-925c9f099a1b)

## Boss Fight:
![Boss_Fight](https://github.com/user-attachments/assets/48be1ad4-8ea0-4380-8bc5-d2631a5f08ee)


