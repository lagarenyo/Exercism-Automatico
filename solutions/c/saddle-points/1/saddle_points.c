#include "saddle_points.h"

saddle_points_t *saddle_points(int x, int y, uint8_t mat[x][y])
{
    saddle_points_t *res;
    uint8_t points[x][y];
    uint8_t max_x[x];
    uint8_t min_y[y];
    int count;

    res = (saddle_points_t *)malloc(sizeof(saddle_points_t));
    for (int i = 0; i < x; i++)
    {
        max_x[i] = mat[i][0];
        for (int j = 1; j < y; j++)
            if (mat[i][j] > max_x[i])
                max_x[i] = mat[i][j];
    }
    for (int i = 0; i < y; i++)
    {
        min_y[i] = mat[0][i];
        for (int j = 1; j < x; j++)
            if (mat[j][i] < min_y[i])
                min_y[i] = mat[j][i];
    }
    count = 0;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
        {
            if ((max_x[i] == min_y[j]) && (max_x[i] == mat[i][j]))
            {
                points[i][j] = 1;
                count++;
            }
            else
                points[i][j] = 0;
        }
    res->points = malloc(count * sizeof(saddle_point_t));
    res->count = count;
    count = 0;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            if (points[i][j] == 1)
            {
                res->points[count].row = i + 1;
                res->points[count].column = j + 1;
                count++;
            }
    return res;
}

void free_saddle_points(saddle_points_t *sad)
{
    free(sad->points);
    free(sad);
}
