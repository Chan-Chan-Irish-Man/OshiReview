#include "utils.h"
#include "mainMenuUI.h"
#include "writeUI.h"

int returnChoice(WINDOW *window, int highlight, int choice, int nChoices,
                 void (*printFn)(WINDOW *, int)) {
  int c;

  printFn(window, highlight);

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
    case 10: // Enter key
      choice = highlight;
      return choice;
    default:
      break;
    }

    printFn(window, highlight);
  }
}
