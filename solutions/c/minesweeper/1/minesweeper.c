#include "minesweeper.h"

char **annotate(const char **minefield, const size_t rows)
{
    char **res;
    int cont;
    size_t max_r;
    size_t max_c;
    size_t col;

    max_r = rows - 1;
    res = NULL;
    if (rows > 0)
    {
        col = 0;
        while (minefield[0][col] != '\0')
            col++;
        max_c = col - 1;
        res = malloc((rows + 1) * sizeof(char *));
        res[rows] = NULL;
        for (size_t i = 0; i < rows; i++)
        {
            res[i] = malloc((col + 1) * sizeof(char));
            res[i][col] = '\0';
        }
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                if (minefield[i][j] != '*')
                {
                    cont = 0;
                    cont += ((i > 0) && (minefield[i - 1][j]) == '*') ? 1 : 0;
                    cont += ((j > 0) && (minefield[i][j - 1]) == '*') ? 1 : 0;
                    cont += ((i < max_r) && (minefield[i + 1][j]) == '*') ? 1 : 0;
                    cont += ((j < max_c) && (minefield[i][j + 1]) == '*') ? 1 : 0;
                    cont += ((i > 0) && (j > 0) && (minefield[i - 1][j - 1]) == '*') ? 1 : 0;
                    cont += ((i < max_r) && (j > 0) && (minefield[i + 1][j - 1]) == '*') ? 1 : 0;
                    cont += ((i < max_r) && (j < max_c) && (minefield[i + 1][j + 1]) == '*') ? 1 : 0;
                    cont += ((i > 0) && (j < max_c) && (minefield[i - 1][j + 1]) == '*') ? 1 : 0;
                    res[i][j] = (cont > 0) ? cont + 48 : ' ';
                }
                else
                    res[i][j] = '*';
            }
        }
    }
    return res;
}

void free_annotation(char **annotation)
{
    int iter;

    iter = 0;
    while (annotation[iter])
        free(annotation[iter++]);
    free(annotation);
}