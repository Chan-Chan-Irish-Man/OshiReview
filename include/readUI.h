#ifndef READUI_H
#define READUI_H

#include "utils.h"
#include "writeUI.h"

#define READBOX_TITLE_X 1
#define READBOX_TITLE_Y 0

int loadReviewsFromFile(Review *reviews, int maxReviews);

void readReviews(void);

#endif
