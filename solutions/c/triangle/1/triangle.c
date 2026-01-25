#include "triangle.h"

static int is_triangle(triangle_t lados)
{
    int res;
    res = (lados.a != 0) && (lados.b != 0) && (lados.c != 0);
    if (res)
        res = (((lados.a + lados.b) >= lados.c) && ((lados.b + lados.c) >= lados.a) && ((lados.a + lados.c) >= lados.b));
    return res;
}

int is_equilateral(triangle_t lados)
{
    int res;

    res = is_triangle(lados);
    if (res)
        res = ((lados.a == lados.b) && (lados.a == lados.c) && (lados.b == lados.c));
    return res;
}

int is_isosceles(triangle_t lados)
{
    int res;

    res = is_triangle(lados);
    if (res)
        res = ((lados.a == lados.b) || (lados.a == lados.c) || (lados.b == lados.c));
    return res;
}

int is_scalene(triangle_t lados)
{
    int res;

    res = is_triangle(lados);
    if (res)
        res = ((lados.a != lados.b) && (lados.a != lados.c) && (lados.b != lados.c));
    return res;
}
