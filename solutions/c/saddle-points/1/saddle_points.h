#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#include <stdlib.h>
#include <stdint.h>

typedef struct
{
    int row;
    int column;
} saddle_point_t;

typedef struct
{
    int count;
    saddle_point_t *points;
} saddle_points_t;

saddle_points_t *saddle_points(int x, int y, uint8_t mat[x][y]);
void free_saddle_points(saddle_points_t *sad);

#endif
