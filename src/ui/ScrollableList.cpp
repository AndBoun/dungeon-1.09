//
// Created By Andrew Boun on 4/22/2025
//

#include <ui/ui.hpp>

// Returns the scroll index
int ui :: render_scrollable_list(int line_start, int line_end, int scroll_idx, std::vector<std::string> &list){
    for (int i = line_start; i < line_end; i++) {
        move(i, 0);
        clrtoeol();
    }

    int visible_count = line_end - line_start;
    int list_size = static_cast<int>(list.size());

    if (visible_count > list_size) {
        visible_count = list_size;
    }

    if (list_size - scroll_idx < visible_count) {
        scroll_idx = list_size - visible_count;
    }
    if (scroll_idx < 0) {
        scroll_idx = 0;
    }

    // int start = static_cast<int>(line_start);
    for (int i = 0; i < visible_count; i++) {
        mvprintw(line_start + i, 0, "%s", list[scroll_idx + i].c_str());
    }

    refresh();

    return scroll_idx;
}