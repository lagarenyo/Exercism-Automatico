#include "crypto_square.h"

static int valid_char(char c)
{
    return (((c >= 'A') && (c <= 'Z')) ||
            ((c >= 'a') && (c <= 'z')) ||
            ((c >= '0') && (c <= '9')));
}
static char down(char c) { return ((c >= 'A') && (c <= 'Z')) ? c + 32 : c; }

char *ciphertext(const char *input)
{
    char *res;
    char *aux;
    int f;
    int c;
    int tam;
    int av;

    tam = 0;
    while (input[tam] != '\0')
        tam++;
    aux = malloc((tam + 1) * sizeof(char));
    tam = 0;
    while (*input != '\0')
    {
        if (valid_char(*input))
        {
            aux[tam] = down(*input);
            tam++;
        }
        input++;
    }
    aux[tam] = '\0';
    f = 0;
    c = 0;

    while ((f * c) < tam)
    {
        if (c == f)
            c++;
        else
            f++;
    }
    res = malloc(((c * (c+1)) + 1) * sizeof(char));
    av = 0;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < f; j++)
        {
            if (((j * c) + i) >= tam)
                res[av] = ' ';
            else
                res[av] = aux[(j * c) + i];
            av++;
        }
        if (i != (c - 1))
        {
            res[av] = ' ';
            av++;
        }
    }
    res[av] = '\0';
    free(aux);
    return res;
}
