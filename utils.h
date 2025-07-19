#ifndef UTILS_H
#define UTILS_H

#include "curses.h"

#define WIDTH 30
#define HEIGHT 10

int returnChoice(WINDOW *window, int highlight, int choice, int nChoices,
                 void (*printFn)(WINDOW *, int));

#endif
