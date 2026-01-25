#ifndef ALL_YOUR_BASE_H
#define ALL_YOUR_BASE_H

#define DIGITS_ARRAY_SIZE 64
#include <stddef.h>
#include <stdint.h>

size_t rebase(int8_t val[static DIGITS_ARRAY_SIZE], int16_t b_ent, int16_t b_sal, size_t d_ent);

#endif
