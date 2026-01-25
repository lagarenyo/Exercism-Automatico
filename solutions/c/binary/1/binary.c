#include "binary.h"

#include <stdio.h>
static int valor(int t)
{
    int res;

    res = 0;
    if (t == 0)
        res = 1;
    else
        res = 2 * valor(t - 1);
    return res;
}

int convert(const char *input)
{
    int indice;
    int aux;
    int res;

    indice = 0;
    res = 0;
    while ((input[indice] != '\0') && (res != -1))
    {
        if ((input[indice] != '0') && (input[indice] != '1'))
            res = -1;
        indice++;
    }
    if (res != -1)
    {
        aux = 0;
        while (indice > 0)
        {
            indice--;
            if (input[indice] == '1')
                res += valor(aux);
            aux++;
        }
    }
    return res;
}
