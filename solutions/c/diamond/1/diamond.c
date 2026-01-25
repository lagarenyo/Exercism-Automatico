#include "diamond.h"

char **make_diamond(const char letter)
{
    char **res;
    int let;
    int tam;
    int max;

    let = letter - 65;
    tam = (let + 1) * 2;
    max = tam - 1;

    res = malloc(tam * sizeof(char *));
    for (int i = 0; i < max; i++)
        res[i] = malloc(tam * sizeof(char));
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
            res[i][j] = ' ';
        res[i][max] = '\0';
    }
    res[max] = NULL;
    max--;
    for (int i = 0; i <= let; i++)
    {
        res[i][let - i] = 65 + i;
        res[i][let + i] = 65 + i;
        res[max - i][let - i] = 65 + i;
        res[max - i][let + i] = 65 + i;
    }
    return res;
}

void free_diamond(char **diamond)
{
    int iter;

    iter = 0;
    while (diamond[iter])
        free((diamond[iter++]));
    free(diamond);
}
