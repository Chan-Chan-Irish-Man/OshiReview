#ifndef MAINMENUUI_H
#define MAINMENUUI_H

#include "curses.h"

#define MAINMENU_TITLE_X 20
#define MAINMENU_TITLE_Y 0

int menuChoose(WINDOW *menuWin, int highlight, int choice, int c);
void menuChoices(int choice);
void printMainMenuUI(WINDOW *menuWin, int highlight);
void mainMenu(void);

#endif
