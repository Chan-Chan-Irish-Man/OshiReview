#include "curses.h"
#include "stdlib.h"

#include "mainMenuUI.h"
#include "readUI.h"
#include "utils.h"
#include "writeUI.h"

static int startX = 0;
static int startY = 0;

static char *choices[] = {
    "[1] Write a Review",
    "[2] See Previous Reviews",
    "[3] Exit",
};
static int nChoices = sizeof(choices) / sizeof(char *);

void menuChoices(int choice) {
  switch (choice) {
  case 1:
    writeReview();
    break;
  case 2:
    readReviews();
    break;
  case 3:
    exit(0);
    break;
  default:
    printw("This simply isn't possible...\n");
    getch();
    break;
  }
}

void printMainMenuUI(WINDOW *menuWin, int highlight) {
  int x = 2, y = 2;

  mvwprintw(menuWin, MAINMENU_TITLE_Y, MAINMENU_TITLE_X, "== OSHI REVIEW ==");

  for (int i = 0; i < nChoices; ++i) {
    if (highlight == i + 1) {
      wattron(menuWin, A_REVERSE);
      mvwprintw(menuWin, y, x, "%s", choices[i]);
      wattroff(menuWin, A_REVERSE);
    } else
      mvwprintw(menuWin, y, x, "%s", choices[i]);
    ++y;
  }
  wrefresh(menuWin);
}

void mainMenu(void) {
  clear();

  WINDOW *menuWin;
  int highlight = INIT_HIGHLIGHT;
  int menuChoice = INIT_CHOICE;

  startX = (MAX_X - WIDTH) / 2;
  startY = (MAX_Y - HEIGHT) / 2;

  menuWin = newwin(HEIGHT, WIDTH, startY, startX);
  keypad(menuWin, TRUE);
  refresh();

  printMainMenuUI(menuWin, highlight);
  menuChoice =
      returnChoice(menuWin, highlight, menuChoice, nChoices, printMainMenuUI);

  menuChoices(menuChoice);
}
