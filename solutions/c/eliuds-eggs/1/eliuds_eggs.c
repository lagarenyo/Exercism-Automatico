#include "eliuds_eggs.h"

int egg_count(int num)
{
    int res;

    res =0;
    if (num < 2)
        res = num;
    else
        res += (num % 2) + egg_count(num / 2);
    return res;
}