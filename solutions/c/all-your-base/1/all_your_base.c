#include "all_your_base.h"

static int valide_data(int8_t val[static DIGITS_ARRAY_SIZE], int16_t b_ent, int16_t b_sal, int16_t d_ent)
{
    int res;

    res = 0;
    if ((b_ent > 1) && (b_sal > 1))
    {
        res = 1;
        for (int i = 0; i < d_ent; i++)
        {
            if ((val[i] >= b_ent) || (val[i] < 0))
                res = 0;
        }
    }
    return res;
}

static void reverse(int8_t val[static DIGITS_ARRAY_SIZE], int16_t d_ent)
{
    int16_t aux;

    d_ent--;
    for (int16_t i = 0; i < d_ent; i++)
    {
        aux = val[i];
        val[i] = val[d_ent];
        val[d_ent] = aux;
        d_ent--;
    }
}

static int16_t to_value(int8_t val[static DIGITS_ARRAY_SIZE], int16_t b_ent, int16_t d_ent)
{
    uint16_t res;
    uint16_t aux;

    res = 0;
    for (int16_t i = 0; i < d_ent; i++)
    {
        aux = 1;
        for (int16_t j = 0; j < i; j++)
            aux *= b_ent;
        res += aux * val[i];
    }
    return res;
}

static size_t to_base(int8_t val[static DIGITS_ARRAY_SIZE], int16_t value, int16_t b_sal)
{
    size_t iter;

    iter = 0;
    while (value >= b_sal)
    {
        val[iter] = value % b_sal;
        value /= b_sal;
        iter++;
    }
    val[iter] = value;
    return ++iter;
}

size_t rebase(int8_t val[static DIGITS_ARRAY_SIZE], int16_t b_ent, int16_t b_sal, size_t d_ent)
{
    int16_t value;
    size_t res;

    res = 0;
    if ((d_ent != 0) && (b_ent > 1) && valide_data(val, b_ent, b_sal, d_ent))
    {
        reverse(val, d_ent);
        value = to_value(val, b_ent, d_ent);
        res = to_base(val, value, b_sal);
        reverse(val, res);
    }
    return res;
}
