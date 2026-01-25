#include "matching_brackets.h"

static int bracket(char c)
{
    int res;

    res = 0;
    if ((c == '[') || (c == '{') | (c == '('))
        res = 1;
    if ((c == ']') || (c == '}') | (c == ')'))
        res = 2;
    return res;
}

static bool par(char a, char b)
{
    bool res;

    res = false;
    if (((a == '[') && (b == ']')) || ((a == '{') && (b == '}')) || ((a == '(') && (b == ')')))
        res = true;
    return res;
}

bool is_paired(const char *input)
{
    bool res;
    char op[25];
    int avance;
    int cont;
    int br;

    res = true;
    cont = 0;
    avance = 0;
    for (int i = 0; i < 25; i++)
        op[i] = 0;
    while ((input[avance] != '\0') && (res))
    {
        br = bracket(input[avance]);
        if (br == 1)
        {
            op[cont] = input[avance];
            cont++;
        }
        if (br == 2)
        {
            if ((cont != 0) && (par(op[cont - 1], input[avance])))
                op[--cont] = '\0';
            else
                res = false;
        }
        avance++;
    }
    if (cont > 0)
        res = false;
    return res;
}
