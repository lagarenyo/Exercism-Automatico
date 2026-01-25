#include "nth_prime.h"

static uint32_t isprime(uint32_t num)
{
    uint32_t max;
    uint32_t val;

    max = num / 2;
    if (num % 2)
    {
        val = 3;
        while (((num % val) != 0) && (val < max))
            val += 2;
        ;
        if (val >= max)
            val = 1;
        else
            val = 0;
    }
    return val;
}

uint32_t nth(uint32_t n)
{
    uint32_t res;

    if (n == 0)
        res = 0;
    else if (n == 1)
        res = 2;
    else
    {
        res = 3;
        for (uint32_t i = 2; i < n; i++)
        {
            res += 2;
            while (!isprime(res))
                res++;
        }
    }
    return res;
}
