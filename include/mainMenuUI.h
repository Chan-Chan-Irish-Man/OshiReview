#ifndef MAINMENUUI_H
#define MAINMENUUI_H

#include "curses.h"

int menuChoose(WINDOW *menuWin, int highlight, int choice, int c);
void menuChoices(int choice);
void printMainMenuUI(WINDOW *menuWin, int highlight);
void mainMenu(void);

#endif
