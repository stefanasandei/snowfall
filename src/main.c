#define _GNU_SOURCE

#include "paint.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

const wchar_t snowflakes[] = {L'❄', L'❅', L'❆', L'❃', L'❊', L'❉', L'❄'};
const size_t SNOW_COUNT = sizeof(snowflakes) / sizeof(wchar_t);

const float density = 5.0f;
const size_t duration = 250000;
const size_t finish = 100;

static volatile int keep_running = 1;

int max_x, max_y, grid_y;
wchar_t grid[501][501];

void gen_grid(void) {
  paint_get_size(&max_x, &max_y);

  for (int y = 0; y < max_y; y++) {
    for (int x = 0; x < max_x; x++) {
      if (((float)rand() / RAND_MAX) < (density / 100.0) &&
          grid[y][x - 1] == ' ') {
        grid[y][x] = snowflakes[rand() % SNOW_COUNT];
      } else {
        grid[y][x] = L' ';
      }
    }
    grid[y][max_x] = L'\0';
  }
}

void snowfall(void) {
  gen_grid();

  int frame = 0;
  while (frame < finish && keep_running == 1) {
    for (int y = max_y; y > 0; y--) {
      wcscpy(grid[y], grid[y - 1]);
    }
    wcscpy(grid[0], grid[max_y]);

    paint_grid(grid, max_x, max_y);

    usleep(duration);
    if (frame != finish - 1)
      paint_clear();

    frame++;
  }
}

void kill_handler() { keep_running = 0; }

int main(int argc, char *argv[]) {
  srand(time(NULL));
  signal(SIGINT, kill_handler);

  paint_init();
  snowfall();
  paint_finish(keep_running);

  printf("Merry Christmas!\n");

  return 0;
}
