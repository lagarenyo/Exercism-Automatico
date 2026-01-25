#include "secret_handshake.h"

static char *act[4] = {"wink", "double blink", "close your eyes", "jump"};

const char **commands(size_t number)
{
    const char **res;
    int code[5];
    int av;
    int cont;

    res = NULL;
    av = 0;
    cont = 0;
    for (int i = 0; i < 5; i++)
        code[i] = 0;
    while ((number > 0) && (av < 5))
    {
        code[av] = number % 2;
        cont += (code[av] == 1) ? 1 : 0;
        number /= 2;
        av++;
    }
    res = (cont > 0) ? malloc((cont + 1) * sizeof(char *)) : malloc(sizeof(char *));
    av = 0;
    res[av] = NULL;
    for (int i = 0; i < 4; i++)
    {
        cont = (code[4] == 1) ? (3 - i) : i;
        if (code[cont] == 1)
        {
            res[av] = act[cont];
            av++;
        }
    }
    return res;
}