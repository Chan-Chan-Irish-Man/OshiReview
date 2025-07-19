#include "curses.h"
#include "locale.h"

#include "menuUI.h"

void initCurses(void) {
  initscr();
  clear();
  noecho();
  cbreak();
  curs_set(0);
}

int main(void) {
  setlocale(LC_ALL, "");

  initCurses();
  mainMenu();
  endwin();
  return 0;
}
