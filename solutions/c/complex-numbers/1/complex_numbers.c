#include "complex_numbers.h"

static double absol(double num) { return (num < 0) ? -num : num; }

static double expo(double exp)
{
   double res, iter;
   int n;

   res = 1.0;
   iter = 1.0;
   n = 1;
   while (n < 1000 && absol(iter) >= 1e-10)
   {
      iter *= exp / n;
      res += iter;
      n++;
   }
   return res;
}

static double raiz(double num)
{
   double res, aux;

   res = num;
   aux = 0;
   while (absol(aux - res) > 1e-10)
   {
      aux = res;
      res = 0.5 * ((num / res) + res);
   }
   return res;
}

static double reduce_angle(double angle)
{
   while (angle > M_PI)
      angle -= 2 * M_PI;
   while (angle < -M_PI)
      angle += 2 * M_PI;
   return angle;
}

static double sin_cos(double num, int val)
{
   double t, res, f, p;
   int n;

   num = reduce_angle(num);
   f = 1;
   res = 0;
   n = 0;
   t = (val == 0) ? num : 1;
   p = t;
   while (absol(t) > 1e-10)
   {
      t = (n % 2 != 0) ? -(p / f) : p / f;
      res += t;
      n++;
      p *= num * num;
      f *= (2 * n) * (2 * n + ((val == 0) ? 1 : -1));
   }
   return res;
}

complex_t c_add(complex_t a, complex_t b)
{
   complex_t res;

   res.real = a.real + b.real;
   res.imag = a.imag + b.imag;
   return res;
}

complex_t c_sub(complex_t a, complex_t b)
{
   complex_t res;

   res.real = a.real - b.real;
   res.imag = a.imag - b.imag;
   return res;
}

complex_t c_mul(complex_t a, complex_t b)
{
   complex_t res;

   res.real = (a.real * b.real) - (a.imag * b.imag);
   res.imag = (a.imag * b.real) + (a.real * b.imag);
   return res;
}

complex_t c_div(complex_t a, complex_t b)
{
   complex_t res;
   double cuad;

   cuad = ((b.real * b.real) + (b.imag * b.imag));
   res.real = ((a.real * b.real) + (a.imag * b.imag)) / cuad;
   res.imag = ((a.imag * b.real) - (a.real * b.imag)) / cuad;
   return res;
}

double c_abs(complex_t x) { return raiz((x.real * x.real) + (x.imag * x.imag)); }

complex_t c_conjugate(complex_t x)
{
   complex_t res;

   res.real = x.real;
   res.imag = (-1) * x.imag;
   return res;
}

double c_real(complex_t x) { return x.real; }

double c_imag(complex_t x) { return x.imag; }

complex_t c_exp(complex_t x)
{
   complex_t res;
   double e;

   e = expo(x.real);
   res.real = e * sin_cos(x.imag, 1);
   res.imag = e * sin_cos(x.imag, 0);
   return res;
}