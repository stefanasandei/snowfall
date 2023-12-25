#include "paint.h"

#include <curses.h>
#include <locale.h>
#include <unistd.h>

void paint_init(void) {
  setlocale(LC_ALL, "");

  initscr();

  keypad(stdscr, true);
  noecho();
  curs_set(0);
}

void paint_finish(int should_getch) {
  if (should_getch == 1) {
    getch();
  }

  endwin();
}

void paint_clear(void) {
  clear();
  refresh();
}

void paint_grid(wchar_t grid[][501], int max_x, int max_y) {
  for (int y = 0; y < max_y; y++) {
    move(y, 0);
    printw("%ls", grid[y]);
  }

  refresh();
}

void paint_get_size(int *max_x, int *max_y) {
  getmaxyx(stdscr, *max_y, *max_x);
}

void paint(void) {}
