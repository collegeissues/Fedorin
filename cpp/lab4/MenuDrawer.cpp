//
// Created by Sterens Nesterov on 11.11.2024.
//

#include "MenuDrawer.h"
#include <ncurses.h>

void MenuDrawer::StartMenu() {
    mvprintw(1,5,"[Start Menu]");
}

void MenuDrawer::StartDrawing() {
    initscr();
    curs_set(0);
    keypad(stdscr,1);
}

