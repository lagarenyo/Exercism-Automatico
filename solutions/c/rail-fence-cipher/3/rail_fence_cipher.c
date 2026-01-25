#include "rail_fence_cipher.h"

static int longit(char *t)
{
    int res;

    res = 0;
    while (t[res] != '\0')
        res++;
    return res;
}
char *encode(char *text, size_t rails)
{
    char *res_enc;
    size_t tam = longit(text) + 1;
    char rail[rails][tam];

    size_t pos[rails];
    size_t r;
    int dir;

    res_enc = malloc(tam * sizeof(char));
    res_enc[tam - 1] = '\0';
    dir = 1;
    for (size_t i = 0; i < rails; i++)
        pos[i] = 0;
    r = 0;
    while (*text != '\0')
    {
        rail[r][pos[r]] = *text;
        pos[r]++;
        if ((r == 0) && (!dir))
        {
            dir = 1;
            r = 1;
        }
        else if ((r == (rails - 1)) && (dir))
        {
            dir = 0;
            r = rails - 2;
        }
        else
            r += (dir) ? 1 : -1;
        text++;
    }
    r = 0;
    for (size_t i = 0; i < rails; i++)
        for (size_t j = 0; j < pos[i]; j++)
        {
            res_enc[r] = rail[i][j];
            r++;
        }
    return res_enc;
}

char *decode(char *ciphertext, size_t rails)
{
    char *res_dec;
    char *aux = ciphertext;
    size_t tam = longit(ciphertext) + 1;
    char rail[rails][tam];

    size_t pos[rails];
    size_t r;
    int dir;

    res_dec = malloc(tam * sizeof(char));
    res_dec[tam-1 ] = '\0';
    dir = 1;
    for (size_t i = 0; i < rails; i++)
        pos[i] = 0;
    r = 0;
    while (*aux != '\0')
    {
        rail[r][pos[r]] = *aux;
        pos[r]++;
        if ((r == 0) && (!dir))
        {
            dir = 1;
            r = 1;
        }
        else if ((r == (rails - 1)) && (dir))
        {
            dir = 0;
            r = rails - 2;
        }
        else
            r += (dir) ? 1 : -1;
        aux++;
    }
    aux = ciphertext;
    for (size_t i = 0; i < rails; i++)
        for (size_t j = 0; j < pos[i]; j++)
        {
            rail[i][j] = *aux;
            aux++;
        }
    aux = res_dec;
    r = 0;
    dir = 1;
    for (size_t i = 0; i < rails; i++)
        pos[i] = 0;
    for (size_t i = 0; i < (tam-1); i++)
    {
        *aux = rail[r][pos[r]];
        pos[r]++;
        if ((r == 0) && (!dir))
        {
            dir = 1;
            r = 1;
        }
        else if ((r == (rails - 1)) && (dir))
        {
            dir = 0;
            r = rails - 2;
        }
        else
            r += (dir) ? 1 : -1;
        aux++;
    }
    return res_dec;
}