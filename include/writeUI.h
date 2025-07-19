#ifndef WRITEUI_H
#define WRITEUI_H

#include "curses.h"

#define WRITEBOX_TITLE_X 20
#define WRITEBOX_TITLE_Y 0

void writeReview(void);
void printReviewMenuUI(WINDOW *menuWin, int highlight);

#endif
