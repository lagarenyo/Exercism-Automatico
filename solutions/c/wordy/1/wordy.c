#include "wordy.h"

static bool compare(const char **question, const char *phrase)
{
    bool res;
    int aux;

    res = false;
    aux = 0;
    while ((*phrase != '\0') && ((*question)[aux] != '\0') && ((*question)[aux] == *phrase))
    {
        aux++;
        phrase++;
    }
    if (*phrase == '\0')
    {
        *question += aux;
        res = true;
    }
    return res;
}

static bool is_digit(char c) { return (c >= '0') && (c <= '9'); }

static bool ext_ope(const char **question, int *ope)
{
    bool res;
    int dim;

    *ope = 0;
    dim = 0;
    res = (**question == '-') ? true : false;
    *question += (res) ? 1 : 0;
    while (is_digit(**question))
    {
        *ope = (*ope * 10) + ((**question) - 48);
        (*question)++;
        dim++;
    }
    *ope *= (res) ? -1 : 1;
    return (dim > 0);
}

bool answer(const char *question, int *result)
{
    bool res;
    bool fin;
    int oper;
    int ope1;
    int ope2;

    res = false;
    fin = false;
    ope1 = 0;
    ope2 = 0;
    oper = 0;
    while (!fin && !res)
    {
        if ((oper != 0) || (compare(&question, "What is ")))
        {
            if ((oper != 0) || (ext_ope(&question, &ope1)))
            {
                if (compare(&question, " plus "))
                    oper = 1;
                else if (compare(&question, " minus "))
                    oper = 2;
                else if (compare(&question, " multiplied by "))
                    oper = 3;
                else if (compare(&question, " divided by "))
                    oper = 4;
                else
                    fin = true;
            }
            else
                fin = true;
            if (ext_ope(&question, &ope2))
            {
                if (oper == 1)
                    ope1 += ope2;
                else if (oper == 2)
                    ope1 -= ope2;
                else if (oper == 3)
                    ope1 *= ope2;
                else if (oper == 4)
                    ope1 /= ope2;
                else
                    fin = true;
            }
            if ((*question == '?'))
                res = true;
        }
        else
            fin = true;
    }
    *result = ope1;
    return res;
}