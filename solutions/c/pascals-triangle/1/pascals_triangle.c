#include "pascals_triangle.h"

void free_triangle(uint8_t **triangle, size_t rows)
{
    size_t dim;

    dim = (rows == 0) ? 1 : rows;
    for (size_t i = 0; i < dim; i++)
        free((triangle)[i]);
    free(triangle);
}

uint8_t **create_triangle(size_t rows)
{
    uint8_t **res;
    size_t dim;

    dim = (rows == 0) ? 1 : rows;
    res = malloc(dim * sizeof(uint8_t *));
    for (size_t i = 0; i < dim; i++)
    {
        res[i] = malloc(dim * sizeof(uint8_t));
        for (size_t j = 0; j < dim; j++)
            res[i][j] = 0;
    }
    if (rows != 0)
    {
        for (size_t i = 0; i < dim; i++)
            for (size_t j = 0; j <= i; j++)
                if (j == 0)
                    res[i][j] = 1;
                else
                    res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
    }
    return res;
}
