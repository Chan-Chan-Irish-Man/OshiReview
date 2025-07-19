#include "writeUI.h"
#include "curses.h"

char *choices[] = {
    "Yes",
    "No",
};
int nChoices = sizeof(choices) / sizeof(char *);

void printReviewMenu(char *oshiName, char *oshiReview) {
  printw("Name: %s\n", oshiName);
  printw("Review: %s\n", oshiReview);
}

void writeReview(void) {
  char oshiName[MAX_NAME_LEN];
  char oshiReview[MAX_REVIEW_LEN];

  echo();
  clear();

  printw("Enter the Virtual Youtuber's name: ");
  getstr(oshiName);

  printw("Write your review: ");
  getstr(oshiReview);

  noecho();
  clear();

  getch();
}
