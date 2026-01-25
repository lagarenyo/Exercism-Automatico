#include "roman_numerals.h"

#include <stdio.h>

static const char let[7] = "IVXLCDM";
static const unsigned int val[7] = {1, 5, 10, 50, 100, 500, 1000};

char *to_roman_numeral(unsigned int number)
{
    char cad_aux[10];
    char *res;
    int pos;
    int aux;
    int prev;
    int iter;

    iter = 0;
    while (number > 0)
    {
        aux = 1;
        pos = 0;
        while (aux != 0)
        {
            prev = pos;
            if ((pos % 2) == 0)
                pos += (number >= (4 * val[pos])) ? 1 : 0;
            else
                pos += (number >= (val[pos] + (4 * val[pos - 1]))) ? 1 : 0;
            aux = (prev == pos) ? 0 : 1;
        }
        if (number >= val[pos])
        {
            cad_aux[iter] = let[pos];
            iter++;
            number -= val[pos];
        }
        else
        {
            cad_aux[iter] = (pos % 2) == 0 ? let[pos - 2] : let[pos - 1];
            iter++;
            cad_aux[iter] = let[pos];
            iter++;
            number -= (pos % 2) == 0 ? (val[pos] - val[pos - 2]) : (val[pos] - val[pos - 1]);
        }
    }
    res = malloc((iter + 1) * sizeof(char));
    res[iter] = '\0';
    for (int i = 0; i < iter; i++)
        res[i] = cad_aux[i];
    return res;
}
