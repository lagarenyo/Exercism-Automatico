#include <math.h>

#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H

typedef struct {
  int numerator; int denominator;
} rational_t;

rational_t add(rational_t rat1, rational_t rat2);
rational_t subtract(rational_t rat1, rational_t rat2);
rational_t multiply(rational_t rat1, rational_t rat2);
rational_t divide(rational_t rat1, rational_t rat2);
rational_t absolute(rational_t rat);
rational_t exp_rational(rational_t rat, int num);
float exp_real(int num, rational_t rat);
//float exp_real(rational_t rat, int num);
rational_t reduce(rational_t rat);

#endif
