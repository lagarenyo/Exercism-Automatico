#include "rational_numbers.h"

static int gcd(int num1, int num2) {
  int aux;
  while (num2 != 0) {
    aux = num1 % num2;
    num1 = num2;
    num2 = aux;
  }
  num1 *= (num1 < 0) ? -1 : 1;
  return num1;
}

rational_t add(rational_t rat1, rational_t rat2) {
  rational_t res;
  res.numerator =
      rat1.numerator * rat2.denominator + rat2.numerator * rat1.denominator;
  res.denominator = rat1.denominator * rat2.denominator;
  return reduce(res);
}

rational_t subtract(rational_t rat1, rational_t rat2) {
  rational_t res;
  res.numerator =
      rat1.numerator * rat2.denominator - rat2.numerator * rat1.denominator;
  res.denominator = rat1.denominator * rat2.denominator;
  return reduce(res);
}

rational_t multiply(rational_t rat1, rational_t rat2) {
  rational_t res;
  res.numerator = rat1.numerator * rat2.numerator;
  res.denominator = rat1.denominator * rat2.denominator;
  return reduce(res);
}

rational_t divide(rational_t rat1, rational_t rat2) {
  rational_t res;
  if (rat2.numerator != 0) {
    res.numerator = rat1.numerator * rat2.denominator;
    res.denominator = rat2.numerator * rat1.denominator;
  } else {
    res.numerator = 0;
    res.denominator = 0;
  }
  return reduce(res);
}

rational_t absolute(rational_t rat) {
  rational_t res;
  res.numerator = (rat.numerator < 0) ? -1 * rat.numerator : rat.numerator;
  res.denominator =
      (rat.denominator < 0) ? -1 * rat.denominator : rat.denominator;
  return reduce(res);
}

rational_t exp_rational(rational_t rat, int num) {
  rational_t res;
  if (num >= 0) {
    res.numerator = pow(rat.numerator, num);
    res.denominator = pow(rat.denominator, num);
  } else {
    num *= -1;
    res.numerator = pow(rat.denominator, num);
    res.denominator = pow(rat.numerator, num);
  }
  return reduce(res);
}

float exp_real(int num, rational_t rat) {
  float aux;
  float res;
  aux = pow(num, 1.0 / rat.denominator);
  res = (rat.numerator != 1) ? pow(aux, rat.numerator) : aux;
  return res;
}

// float exp_real(rational_t rat, int num);
// La exponenciación de un número real `x` a un número racional `r = a/b` es
//  `x^(a/b) = raíz(x^a, b)`, donde `raíz(p, q)` es la `q`ª raíz de `p`.

rational_t reduce(rational_t rat) {
  //  Para reducir un número racional `r = a/b`, hay que dividir `a` y `b` por
  //  el máximo común divisor (gcd) de `a` y `b`.
  rational_t res;
  int aux;
  aux = (rat.numerator > rat.denominator) ? gcd(rat.numerator, rat.denominator)
                                          : gcd(rat.denominator, rat.numerator);
  res.numerator = rat.numerator / aux;
  res.denominator = rat.denominator / aux;
  res.numerator *= (res.denominator < 0) ? -1 : 1;
  res.denominator *= (res.denominator < 0) ? -1 : 1;

  return res;
}
