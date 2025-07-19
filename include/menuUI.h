#ifndef MENUUI_H
#define MENUUI_H

#include "curses.h"

#define WIDTH 30
#define HEIGHT 10

int menuChoose(WINDOW *menuWin, int highlight, int choice, int c);
void menuChoices(int choice);
void printMenu(WINDOW *menuWin, int highlight);
void mainMenu(void);

#endif
