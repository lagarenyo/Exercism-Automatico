#include "spiral_matrix.h"

void spiral_matrix_destroy(spiral_matrix_t *mat)
{
    for (int i = 0; i < mat->size; i++)
        free(mat->matrix[i]);
    free(mat->matrix);
    free(mat);
}

spiral_matrix_t *spiral_matrix_create(int num)
{
    spiral_matrix_t *res;
    int iter;
    res = (spiral_matrix_t *)malloc((sizeof(spiral_matrix_t)));
    res->size = num;
    if (num != 0)
    {
        res->matrix = malloc(num * sizeof(int *));
        for (int i = 0; i < num; i++)
            res->matrix[i] = (int *)malloc(num * sizeof(int));
        iter = 1;
        num--;
        for (int i = 0; i <= num; i++)
        {
            if (i < num)
            {
                for (int j = i; j < num; j++)
                    res->matrix[i][j] = iter++;
                for (int j = i; j < num; j++)
                    res->matrix[j][num] = iter++;
                for (int j = num; j > i; j--)
                    res->matrix[num][j] = iter++;
                for (int j = num; j > i; j--)
                    res->matrix[j][i] = iter++;
            }
            else
                res->matrix[i][i] = iter;
            num--;
        }
    }
    else
        res->matrix = 0;
    return res;
}