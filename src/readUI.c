#include "readUI.h"
#include "curses.h"
#include "string.h"
#include "utils.h"

int readReviewsFromFile(Review *reviews, int maxReviews) {
  FILE *file = fopen("reviews.txt", "r");
  if (!file) {
    perror("Failed to open file.");
    return -1;
  }

  char line[MAX_LINE_LEN];
  int count = 0;

  while (fgets(line, sizeof(line), file) && count < maxReviews) {
    line[strcspn(line, "\n")] = 0;

    const char *oshiName = strtok(line, "|");
    const char *review = strtok(NULL, "|");

    if (oshiName && review) {
      strncpy(reviews[count].oshiName, oshiName, MAX_NAME_LEN - 1);
      reviews[count].oshiName[MAX_NAME_LEN - 1] = '\0';
      strncpy(reviews[count].review, review, MAX_REVIEW_LEN - 1);
      reviews[count].review[MAX_REVIEW_LEN - 1] = '\0';
      count++;
    }
  }

  fclose(file);
  return count;
}

static Review *sharedReviews = NULL;
static int sharedReviewCount = 0;

static void printReviewsUI(WINDOW *win, int highlight) {
  int x = 2, y = 2;

  werase(win);
  box(win, '|', '=');

  mvwprintw(win, READBOX_TITLE_Y, READBOX_TITLE_X,
            "REVIEWS (%d total, arrows to scroll, ENTER to select)",
            sharedReviewCount);
  for (int i = 0; i < sharedReviewCount; ++i) {
    if (i == highlight - 1)
      wattron(win, A_REVERSE);

    mvwprintw(win, y, x, "%s: %s", sharedReviews[i].oshiName,
              sharedReviews[i].review);

    if (i == highlight - 1)
      wattroff(win, A_REVERSE);

    ++y;
  }

  wrefresh(win);
}

void readSelectedReview(int reviewChoice, Review reviews[], int startY,
                        int startX) {
  WINDOW *selectedReviewWin;

  selectedReviewWin = newwin(HEIGHT, WIDTH, startY, startX);
  box(selectedReviewWin, '|', '=');

  mvwprintw(selectedReviewWin, READBOX_TITLE_Y, READBOX_TITLE_X,
            "== %s ==", reviews[reviewChoice].oshiName);

  mvwprintw(selectedReviewWin, READBOX_BODY_Y, READBOX_BODY_X, "%s",
            reviews[reviewChoice].review);

  touchwin(selectedReviewWin);
  wrefresh(selectedReviewWin);

  getch();
  delwin(selectedReviewWin);
}

void readReviews(void) {
  static Review reviews[MAX_REVIEWS];
  sharedReviews = reviews;

  sharedReviewCount = readReviewsFromFile(reviews, MAX_REVIEWS);
  if (sharedReviewCount <= 0) {
    clear();
    mvprintw(0, 0, "No reviews found. Press any key to return.");
    getch();
    return;
  }

  WINDOW *reviewWin;
  int highlight = INIT_HIGHLIGHT;
  int reviewChoice = INIT_CHOICE;

  int startY = (MAX_Y - HEIGHT) / 2;
  int startX = (MAX_X - WIDTH) / 2;

  reviewWin = newwin(HEIGHT, WIDTH, startY, startX);
  keypad(reviewWin, TRUE);
  refresh();

  reviewChoice = returnChoice(reviewWin, highlight, reviewChoice,
                              sharedReviewCount, printReviewsUI);

  werase(reviewWin);
  wrefresh(reviewWin);
  delwin(reviewWin);

  readSelectedReview(reviewChoice, reviews, startY, startX);

  clear();
}
