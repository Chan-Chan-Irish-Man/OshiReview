#include "writeUI.h"
#include "curses.h"
#include "mainMenuUI.h"
#include "stdio.h"
#include "utils.h"

static int startX = 0;
static int startY = 0;

static char *choices[] = {
    "Save",
    "Retry",
};
static int nChoices = sizeof(choices) / sizeof(char *);

void addReviewToFile(const char *oshiName, const char *review) {
  FILE *file = fopen("reviews.txt", "a");
  if (!file) {
    perror("Failed to open file.");
    return;
  }

  fprintf(file, "%s|%s\n", oshiName, review); // Use | as delimiter
  fclose(file);
}

void printReviewMenuUI(WINDOW *menuWin, int highlight) {
  int x = 2, y = 2;

  box(menuWin, '|', '=');
  mvwprintw(menuWin, WRITEBOX_TITLE_Y, WRITEBOX_TITLE_X,
            "== CONFIRM REVIEW ==");

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

void reviewChoices(int reviewChoice, const char *oshiName, const char *review) {
  switch (reviewChoice) {
  case 0:
    addReviewToFile(oshiName, review);
    mainMenu();
    break;
  case 1:
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
  int highlight = INIT_HIGHLIGHT;
  int reviewChoice = INIT_CHOICE;

  startX = (MAX_X - WIDTH) / 2;
  startY = (MAX_Y - HEIGHT) / 2;

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

  reviewChoice = returnChoice(reviewWin, highlight, reviewChoice, nChoices,
                              printReviewMenuUI);

  reviewChoices(reviewChoice, oshiName, oshiReview);

  noecho();
  clear();

  getch();
}
