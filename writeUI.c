#include "writeUI.h"
#include "curses.h"
#include "utils.h"

static int startX = 0;
static int startY = 0;

static char *choices[] = {
    "Yes",
    "No",
};
static int nChoices = sizeof(choices) / sizeof(char *);

void printReviewMenuUI(WINDOW *menuWin, int highlight) {
  int x = 2, y = 2;

  box(menuWin, 0, 0);
  mvwprintw(menuWin, 0, 2, "== CONFIRM REVIEW ==");

  for (int i = 0; i < nChoices; ++i) {
    if (highlight == i + 1) {
      wattron(menuWin, A_REVERSE);
      mvwprintw(menuWin, y, x, "%s", choices[i]);
      wattroff(menuWin, A_REVERSE);
    } else {
      mvwprintw(menuWin, y, x, "%s", choices[i]);
    }
    ++y;
  }
  wrefresh(menuWin);
}

void reviewChoices(int reviewChoice) {
  switch (reviewChoice) {
  case 1:
    printw("Returning to Menu...");
    getch();
    break;
  case 2:
    writeReview();
    break;
  default:
    printw("This simply isn't possible...\n");
    getch();
    break;
  }
}

void writeReview(void) {
  WINDOW *reviewWin;
  int highlight = 1;
  int reviewChoice = 0;

  startX = (80 - WIDTH) / 2;
  startY = (24 - HEIGHT) / 2;

  reviewWin = newwin(HEIGHT, WIDTH, startY, startX);
  keypad(reviewWin, TRUE);
  refresh();

  char oshiName[MAX_NAME_LEN];
  char oshiReview[MAX_REVIEW_LEN];

  echo();
  clear();

  printw("Enter the Virtual Youtuber's name: ");
  getstr(oshiName);

  printw("Write your review: ");
  getstr(oshiReview);

  printReviewMenuUI(reviewWin, highlight);

  printw("Is this okay?: ");
  reviewChoice = returnChoice(reviewWin, highlight, reviewChoice, nChoices,
                              printReviewMenuUI);

  reviewChoices(reviewChoice);

  noecho();
  clear();

  getch();
}
