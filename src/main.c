#include <curses.h>
#include <locale.h>

void paint(void) {
  initscr();

  keypad(stdscr, true);
  noecho();
  curs_set(0);

  int max_x, max_y;
  getmaxyx(stdscr, max_y, max_x);

  move(max_y / 2, max_x / 2);
  printw("%ls\n", L"❄<");

  getch();
  endwin();
}

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "");

  printf("Merry Christmas!\n");

  paint();
  return 0;
}
