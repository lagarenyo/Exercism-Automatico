#include "series.h"

static unsigned int dimension(char *cad)
{
    int res;

    res = 0;
    while (*cad != '\0')
    {
        cad++;
        res++;
    }
    return res;
}

slices_t slices(char *input_text, unsigned int substring_length)
{
    slices_t res;
    unsigned tam;

    tam = dimension(input_text);
    res.substring_count = ((tam >= substring_length) && (substring_length > 0)) ? tam + 1 - substring_length : 0;
    if (res.substring_count > 0)
    {
        res.substring = malloc((res.substring_count + 1) * sizeof(char *));
        for (unsigned int i = 0; i < res.substring_count; i++)
        {
            res.substring[i] = malloc((substring_length + 1) * sizeof(char));
            for (unsigned int j = 0; j < substring_length; j++)
                res.substring[i][j] = input_text[i + j];
            res.substring[i][substring_length] = '\0';
        }
    }
    return res;
}
