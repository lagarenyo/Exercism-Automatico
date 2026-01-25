#include "prime_factors.h"
#include <stdio.h>

static uint64_t listprime[71000];

static void addprime(int pos)
{
    int stop;
    int iter;
    uint64_t val;
    uint64_t aux;

    val = listprime[pos - 1] + 2;
    aux = val / 2;
    stop = 0;
    iter = 0;
    while (!stop)
    {
        while (((val % listprime[iter]) != 0) && (listprime[iter] < aux))
            iter++;

        if ((val % listprime[iter]) != 0)
        {
            listprime[pos] = val;
            stop = 1;
        }
        else
        {
            val += 2;
            iter = 0;
        }
    }
}

static void initlist()
{
    listprime[0] = 2;
    listprime[1] = 3;
    listprime[2] = 5;
    listprime[3] = 7;
    listprime[4] = 11;
    listprime[5] = 13;
    listprime[6] = 17;
    listprime[7] = 19;
    listprime[8] = 23;
    listprime[9] = 29;
    for (int i = 10; i < 71000; i++)
        addprime(i);
}

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
    int iterprime;
    int iterfac;

    iterprime = 0;
    iterfac = 0;
    if (listprime[0] != 2)
        initlist();
    while (n > 1)
    {
        while ((listprime[iterprime] != 0) && ((n % listprime[iterprime]) != 0))
            iterprime++;
        n /= listprime[iterprime];
        factors[iterfac] = listprime[iterprime];
        iterfac++;
        iterprime = 0;
    }
    return iterfac;
}
