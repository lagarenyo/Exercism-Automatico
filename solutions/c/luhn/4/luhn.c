#include "luhn.h"

static int valida(const char *num)
{
    int res;
    bool err;

    res = 0;
    err = false;
    while ((!err) && (*num) != '\0')
    {
        if (((*num) >= '0') && ((*num) <= '9'))
            res++;
        else if ((*num) != ' ')
            err = true;
        num++;
    }
    return err ? 0 : res;
}

static int *prepara(const char *num, int tam)
{
    int *res;
    int iter;

    res = malloc((tam + 1) * sizeof(int));
    iter = 0;
    while (*num)
    {
        if (*num != ' ')
        {
            res[iter] = (*num) - 48;
            iter++;
        }
        num++;
    }
    return res;
}

bool luhn(const char *num)
{
    bool res;
    int sum;
    int tam;
    int iter;
    int *dato;
    int aux;

    tam = valida(num);
    sum = 0;
    res = true;
    if (tam > 1)
    {
        iter = 1;
        dato = prepara(num, tam);
        while (iter <= tam)
        {
            if ((iter % 2) == 0)
            {
                aux = 2 * dato[tam - iter];
                if (aux > 9)
                    sum += (aux - 9);
                else
                    sum += aux;
            }
            else
                sum += dato[tam - iter];
            iter++;
        }
    }
    else
        res = false;
    if (res)
        res = ((sum % 10) == 0) ? true : false;
    //free(dato);
    return res;
}