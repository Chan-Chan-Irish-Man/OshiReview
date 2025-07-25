#include "curses.h"
#include "locale.h"

#include "mainMenuUI.h"

void initCurses(void) {
  initscr();
  clear();
  noecho();
  cbreak();
  curs_set(0);
}

int main(void) {
  setlocale(LC_ALL, "en_US.UTF-8");

  initCurses();
  mainMenu();
  endwin();
  return 0;
}
