#ifndef READUI_H
#define READUI_H

#include "utils.h"
#include "writeUI.h"

#define READBOX_TITLE_Y 1
#define READBOX_TITLE_X 2
#define READBOX_BODY_Y 3
#define READBOX_BODY_X 2

int loadReviewsFromFile(Review *reviews, int maxReviews);

void readReviews(void);

#endif
