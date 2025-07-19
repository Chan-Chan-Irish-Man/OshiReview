#ifndef UTILS_H
#define UTILS_H

#include "curses.h"

#define MAX_NAME_LEN 100
#define MAX_REVIEW_LEN 900
#define MAX_REVIEWS 100
#define WIDTH 60
#define HEIGHT 20
#define MAX_LINE_LEN 1024
#define INIT_HIGHLIGHT 1
#define INIT_CHOICE 0
#define MAX_X 80
#define MAX_Y 24

typedef struct {
  char oshiName[MAX_NAME_LEN];
  char review[MAX_REVIEW_LEN];
} Review;

int returnChoice(WINDOW *window, int highlight, int choice, int nChoices,
                 void (*printFn)(WINDOW *, int));

#endif
