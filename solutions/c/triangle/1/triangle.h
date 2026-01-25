#ifndef TRIANGLE_H
#define TRIANGLE_H

typedef struct
{
   double a;
   double b;
   double c;
} triangle_t;

int is_equilateral(triangle_t lados);
int is_isosceles(triangle_t lados);
int is_scalene(triangle_t lados);

#endif
