//
// Created By Andrew Boun on 4/2/2025
//

#ifndef UI_HPP
#define UI_HPP

#include <dungeon/Dungeon.hpp>
#include <ncurses.h>

constexpr int COLOR_DEFAULT_ID = 1;
constexpr int COLOR_PLAYER_ID = 2;
constexpr int COLOR_STAIR_ID = 3;
constexpr int COLOR_SUCCESS_ID = 3;
constexpr int COLOR_MONSTER_ID = 4;
constexpr int COLOR_ERROR_ID = 5;
constexpr int COLOR_WARNING_ID = 6;

class ui {
    private:
        // Private member variables if needed
        static int handle_player_movement(Dungeon &d, int x, int y);
        static int print_monster_list(Dungeon &d, NPC alive[], int scroll);

        // helper for render_centered_line
        // static void render_centered_line_v(int line, int color_id, const char *format, va_list args);
        

    public:
        // Constructor and destructor
        ui() = delete;
        ~ui() = delete;
        
        // Initialize and destroy ncurses
        static void init_ncurses();
        static void destroy_ncurses();
        
        // Rendering status methods
        static void render_centered_line(int line, int color_id, const char *format, ...);
        static void render_pc_status(Dungeon &d);

        // Render status bars overloads
        template<typename... Args>
        static void render_top_bar(int color_id, const char *format, Args&&... args) {render_centered_line(0, color_id, format, std::forward<Args>(args)...);}

        template<typename... Args>
        static void render_status_1(int color_id, const char *format, Args&&... args) {render_centered_line(23, color_id, format, std::forward<Args>(args)...);}

        template<typename... Args>
        static void render_status_2(int color_id, const char *format, Args&&... args) {render_centered_line(24, color_id, format, std::forward<Args>(args)...);}

        static void clear_top_bar() {render_top_bar(COLOR_DEFAULT_ID, "");}
        static void clear_status_1() {render_status_1(COLOR_DEFAULT_ID, "");}
        static void clear_status_2() {render_status_2(COLOR_DEFAULT_ID, "");}


        static void render_grid(const Dungeon &d, const std::array<std::array<Cell, DUNGEON_WIDTH>, DUNGEON_HEIGHT> &grid, bool is_fog_on = false);
        static void render_game_over(Dungeon &d);
        static bool teleport(Dungeon &d);
        
        // Input handling
        static int get_input(Dungeon &d);
        static int handle_monster_list(Dungeon &d);
        static bool selectMonster(Dungeon &d);
        static bool displayMonsterInfo(Dungeon &d, Point p);

        static void init_NPC_colors(std::vector<NPC*> npcs);
        static void init_item_colors(std::vector<Item*> items);
};

#endif // NCURSES_UI_HPP