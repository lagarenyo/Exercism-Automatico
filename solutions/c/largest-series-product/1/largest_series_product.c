#include "largest_series_product.h"

static int64_t is_number_leng(char *cad)
{
    int64_t res;
    int aux;

    res = 0;
    aux = 1;
    while ((res >= 0) && (cad[res] != '\0') && aux)
        if ((cad[res] >= '0') && (cad[res] <= '9'))
            res++;
        else
            aux = 0;
    return (aux) ? res : 0;
}

static int64_t valor(char *digits, size_t span)
{
    int64_t res;

    res = 1;
    for (size_t i = 0; i < span; i++)
        res = res * (digits[i] - 48);
    return res;
}

int64_t largest_series_product(char *digits, size_t span)
{
    int64_t res;
    int64_t aux;
    size_t tam;

    tam = is_number_leng((digits));
    res = -1;
    if ((tam > 0) && (span > 0) && (span <= tam))
    {
        for (size_t i = 0; i <= (tam - span); i++)
        {
            aux = valor(digits + i, span);
            if (aux > res)
                res = aux;
        }
    }
    return res;
}