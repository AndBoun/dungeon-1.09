//
// Created By Andrew Boun on 4/22/2025
//

#include <ui/ui.hpp>

void ui::render_inventory(Dungeon &d)
{
    clear();

    render_top_bar(COLOR_DEFAULT_ID, "In Inventory, press 'q' or ESC to exit");

    mvprintw(2, 0, "Weapon: %s", Item::print_name_symbol(d.pc.weapon_slot).c_str());
    mvprintw(3, 0, "Offhand: %s", Item::print_name_symbol(d.pc.offhand_slot).c_str());
    mvprintw(4, 0, "Ranged: %s", Item::print_name_symbol(d.pc.range_slot).c_str());
    mvprintw(5, 0, "Armor: %s", Item::print_name_symbol(d.pc.armor_slot).c_str());
    mvprintw(6, 0, "Helmet: %s", Item::print_name_symbol(d.pc.helmet_slot).c_str());
    mvprintw(7, 0, "Cloak: %s", Item::print_name_symbol(d.pc.cloak_slot).c_str());
    mvprintw(8, 0, "Gloves: %s", Item::print_name_symbol(d.pc.gloves_slot).c_str());
    mvprintw(9, 0, "Boots: %s", Item::print_name_symbol(d.pc.boots_slot).c_str());
    mvprintw(10, 0, "Amulet: %s", Item::print_name_symbol(d.pc.amulet_slot).c_str());
    mvprintw(11, 0, "Light: %s", Item::print_name_symbol(d.pc.light_slot).c_str());
    mvprintw(12, 0, "Ring 1: %s", Item::print_name_symbol(d.pc.ring_slot_1).c_str());
    mvprintw(13, 0, "Ring 2: %s", Item::print_name_symbol(d.pc.ring_slot_2).c_str());

    refresh();

    int input;
    do
    {
        timeout(-1);
        input = getch();

        if (input == 'Q')
        {
            destroy_ncurses();
            printf("Game terminated by user\n");
            exit(0);
            break;
        }
    } while (input != 'q' && input != 'i' && input != 27);

    clear_top_bar();
    render_grid_default(d);
}

void ui::render_equipment(Dungeon &d)
{
    clear();

    int size = d.getPC().items.size();
    int i = 0;

    render_top_bar(COLOR_DEFAULT_ID, "In Equipment View, press 'q' or ESC to exit");

    int line = 2; // starting line
    for (; i < size; i++)
    {
        mvprintw(line++, 0, "Slot %d : %s", i, Item::print_name_symbol(d.getPC().items[i]).c_str());
    }

    for (; i < 10 /* max inventory size*/; i++)
    {
        mvprintw(line++, 0, "Slot %d : EMPTY", i);
    }

    refresh();

    int input;
    do
    {
        timeout(-1);
        input = getch();

        quit_game(d, input);
    } while (input != 'q' && input != 'e' && input != 27);

    clear_top_bar();
    render_grid_default(d);
}

void ui::inspect_item(Dungeon &d)
{

    Item *item = get_item_from_inventory(d);

    if (item == nullptr)
    {
        return;
    }

    Dice dice = item->dice_dam;

    std::vector<std::string> display_list = {
        "Name: " + item->name,
        "Type: " + item->type,
        "Symbol: " + std::string(1, item->symbol),
        "Hit: " + std::to_string(item->hit),
        "Damage: " + std::to_string(dice.base) + "+" + std::to_string(dice.numDice) + "d" + std::to_string(dice.numSides),
        "Dodge: " + std::to_string(item->dodge),
        "Defense: " + std::to_string(item->def),
        "Weight: " + std::to_string(item->weight),
        "Speed: " + std::to_string(item->speed),
        "Attribute: " + std::to_string(item->attr),
        "Value: " + std::to_string(item->val),
        "Art: " + std::to_string(item->art),
        "Rarity: " + std::to_string(item->rrty),
        "" // Empty line for spacing
    };

    // Process description text into lines
    std::string desc = item->desc;
    std::string current_line;
    for (size_t i = 0; i < desc.length(); i++)
    {
        if (current_line.length() >= 78 || desc[i] == '\n')
        {
            display_list.push_back(current_line);
            current_line.clear();
        }
        else
        {
            current_line += desc[i];
        }
    }

    int scroll = 0;
    clear();
    render_top_bar(COLOR_WARNING_ID, "In Item Inspection Mode, press 'q' or ESC to exit");
    render_scrollable_list(2, 24, scroll, display_list);
    while (true)
    {
        timeout(-1);
        int input = getch();

        if (input == KEY_UP)
        {
            scroll = render_scrollable_list(2, 24, --scroll, display_list);
        }
        else if (input == KEY_DOWN)
        {
            scroll = render_scrollable_list(2, 24, ++scroll, display_list);
        }

        if (input == 'q' || input == 27 || input == 'I')
        {
            // Clear the screen and return to the main menu
            clear();
            render_grid_default(d);

            render_top_bar(COLOR_SUCCESS_ID, "Exited item inspection mode");
            break;
        }

        quit_game(d, input);
    }

    return;
}
