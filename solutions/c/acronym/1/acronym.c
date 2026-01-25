#include "acronym.h"

static int is_let(char c)
{
    int res;

    res = 0;
    if (((c > 64) && (c < 91)) || ((c > 96) && (c < 123)))
        res = 1;
    return res;
}

char *abbreviate(const char *phrase)
{
    char aux[25];
    char *res;
    int iter;
    int init;

    init = 1;
    iter = 0;
    aux[24] = '\0';
    res = NULL;
    if (phrase)
    {
        while (*phrase != '\0')
        {
            if ((*phrase == ' ') || (*phrase == '-'))
                init = 1;
            if ((is_let(*phrase)) && init)
            {
                aux[iter] = *phrase;
                if (aux[iter] > 96)
                    aux[iter] -= 32;
                iter++;
                init = 0;
            }
            phrase++;
        }
        if (iter > 0)
        {
            res = malloc((iter + 1) * sizeof(char));
            for (int i = 0; i < iter; i++)
                res[i] = aux[i];
            res[iter] = '\0';
        }
    }
    return res;
}