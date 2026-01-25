#include "high_scores.h"

#include <stdio.h>

static void inserta( int32_t num, int32_t *output)
{
    size_t iter;
    int32_t aux;

    for (iter = 0; iter < 3; iter++)
    {
        if (output[iter] == -1)
        {
            output[iter] = num;
            iter = 3;
        }
        else if (num > output[iter])
        {
            aux = output[iter];
            output[iter] = num;
            num = aux;
        }
    }
}

int32_t latest(const int32_t *scores, size_t scores_len)
{
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len)
{
    int32_t res;
    size_t i;
    res = 0;
    for (i = 0; i < scores_len; i++)
        if (scores[i] > res)
            res = scores[i];
    return res;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output)
{
    size_t iter;
    size_t avance;

    avance = 0;
    for (iter = 0; iter < 3; iter++)
        output[iter] = -1;
    while (avance < scores_len)
    {
        inserta(scores[avance], output);
        avance++;
    }
    return (scores_len < 3) ? scores_len : 3;
}
