#include "perfect_numbers.h"

static int sumaalicuota(int num)
{
    int res;
    int medio;
    int iter;

    medio = num / 2;
    res = 0;
    for (iter = 1; iter <= medio; iter++)
        res += ((num % iter) == 0) ? iter : 0;
    return res;
}

kind classify_number(int num)
{
    int valor;
    kind res;

    if (num <= 0)
        res = ERROR;
    else
    {
        valor = sumaalicuota(num);
        return (valor == num) ? PERFECT_NUMBER : (valor > num) ? ABUNDANT_NUMBER
                                                               : DEFICIENT_NUMBER;
    }
    return res;
}