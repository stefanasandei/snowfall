#ifndef PAINT_H
#define PAINT_H

#include <wchar.h>

void paint_init(void);
void paint_finish(int should_getch);

void paint_clear(void);
void paint_grid(wchar_t grid[][501], int max_x, int max_y);

void paint_get_size(int *max_x, int *max_y);

void paint(void);

#endif
