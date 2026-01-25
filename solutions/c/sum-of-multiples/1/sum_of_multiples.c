#include "sum_of_multiples.h"

#include <stdio.h>

static unsigned int evalua(const unsigned int *factors, unsigned int *as, unsigned int num_factor, unsigned int numelem)
{
    unsigned int multip[numelem];
    unsigned int av, iter, avan, res;

    av = 0;
    avan = 0;
    res = 0;

    while (av < num_factor)
    {
        for (iter = 1; iter <= (as[av]); iter++)
            multip[avan++] = factors[av] * iter;
        av++;
    }
    iter = 0;
    while (iter < numelem)
    {
        if (multip[iter] != 0)
        {
            res += multip[iter];
            for (av = (iter + 1); av < numelem; av++)
                if (multip[av] == multip[iter])
                    multip[av] = 0;
        }
        iter++;
    }
    return res;
}

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit)
{
    unsigned int numelem;
    unsigned int ad[number_of_factors], i;

    numelem = 0;
    for (i = 0; i < number_of_factors; i++)
        ad[i] = (factors[i] == 0) ? 0 : ((limit % factors[i]) == 0) ? (limit / factors[i]) - 1
                                                                    : limit / factors[i];
    for (i = 0; i < number_of_factors; i++)
        numelem += ad[i];
    return (evalua(factors, ad, number_of_factors, numelem));
}

/*
int main()

{
    const unsigned int multi[] = {3, 5};

    printf("sum: %i\n", sum(multi, 2, 4));

    return 1;
}

*/
