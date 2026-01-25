#ifndef DARTS_H
#define DARTS_H

#include <stdint.h>
#include <math.h>

typedef struct
{
    double_t x;
    double_t y;
} coordinate_t;

uint8_t score(coordinate_t coordenada);
#endif
