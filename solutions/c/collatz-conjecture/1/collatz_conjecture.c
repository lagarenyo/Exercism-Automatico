#include "collatz_conjecture.h"

int steps(int start)
{
    int cont;

    cont = 0;
    if (start < 1)
        cont = -1;
    else
    {
        while (start > 1)
        {
            if ((start % 2) == 0)
            {
                start /= 2;
                cont++;
            }
            else
            {
                start *= 3;
                start++;
                cont++;
            }
        }
    }
    return cont;
}