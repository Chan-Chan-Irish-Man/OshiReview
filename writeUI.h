#ifndef WRITEUI_H
#define WRITEUI_H

#include "curses.h"

#define MAX_NAME_LEN 30
#define MAX_REVIEW_LEN 255

void writeReview(void);
void printReviewMenuUI(WINDOW *menuWin, int highlight);

#endif
