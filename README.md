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
- 10 to 20 items are randomly generate per level
- Players keep their carry and equipment items between levels.
- Item features for the PC only include bonus speed and damage (as that was listed for 1.09). Other item features (dodge, light radius, etc.) are not implemented.
- Item pickup only works for the player. Move over items to pick them up.
- Item stacking isn't explicitly implemented, the game prevents objects from generating on top of each other, but if the player forcefully drops multiple items in the same spot, any of the symbols of that item may appear at that position, and you may pick up at an item at that position as many times as there is an item there.

## How the Project Runs:
In `main.cpp`, it creates a dungeon instance, `start_gameplay()` in `Dungeon.cpp`.  When it's a character's turn, `MonsterMovement.cpp` or `PlayerMovement.cpp` will be called. In `MonsterMovement.cpp`, monsters `displaceNPC()` instead of killing each other. When a Monster of Player attacks, they stay in place, and call `attackCharacter()` in `DungeonCombat.cpp`. When it's a player turn to move, in `ui.cpp`, they can use all the new controls.  `ScrollableList.cpp` is a helper function to render a scrollable list based on each string array, where each line is a entry in the array. `RenderItems.cpp` render the equipment and inventory. `ItemSelection.cpp` are helper functions for that allow the player to select a carry or equipment slot for the other functions. `InspectMonster.cpp` handles selecting and inspecting a monster. `HandleItem.cpp` deals with inspecting, expunging, dropping, wearing, and taking off items. You can only win the game by killing a BOSS now. Creating a dungeon without monsters means you can never win the game.


# Example Gameplay: