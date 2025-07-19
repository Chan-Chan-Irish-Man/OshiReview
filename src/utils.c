#include "utils.h"
#include "menuUI.h"
#include "writeUI.h"

int returnChoice(WINDOW *window, int highlight, int choice, int nChoices,
                 void (*printFn)(WINDOW *, int)) {
  int c;

  while (1) {
    c = wgetch(window);
    switch (c) {
    case KEY_UP:
      if (highlight == 1)
        highlight = nChoices;
      else
        --highlight;
      break;
    case KEY_DOWN:
      if (highlight == nChoices)
        highlight = 1;
      else
        ++highlight;
      break;
    case 10:
      choice = highlight;
      return choice;
      break;
    default:
      refresh();
      break;
    }
    printFn(window, highlight);
  }
  clrtoeol();
  refresh();
}
