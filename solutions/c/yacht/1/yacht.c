#include "yacht.h"

#include <stdio.h>

static int cont[6];

static int val_cat(dice_t dice, category_t category)
{
    int res;

    res = 1;
    for (int i = 0; i < 5; i++)
        cont[dice.faces[i] - 1]++;
    switch (category)
    {
    case 6:
        for (int i = 0; i < 6; i++)
            if ((cont[i] != 0) && (cont[i] != 2) && (cont[i] != 3))
                res = 0;
        break;
    case 7:
        res = 0;
        for (int i = 0; i < 6; i++)
            if (cont[i] >= 4)
                res = 1;
        break;
    case 8:
        for (int i = 0; i < 5; i++)
            if (cont[i] != 1)
                res = 0;
        break;
    case 9:
        for (int i = 1; i < 6; i++)
            if (cont[i] != 1)
                res = 0;
        break;
    case 11:
        res = 0;
        for (int i = 0; i < 6; i++)
            if (cont[i] == 5)
                res = 1;
        break;
    default:;
    }
    return res;
}

int score(dice_t dice, category_t category)
{
    int res;

    res = 0;
    for (int i = 0; i < 6; i++)
        cont[i] = 0;
    if (val_cat(dice, category))
    {
        if (category < 6)
            res = (category + 1) * cont[category];
        else if ((category == 6) || (category == 10))
            for (int i = 0; i < 6; i++)
                res += cont[i] * (i + 1);
        else if (category == 7)
            for (int i = 0; i < 6; i++)
            {
                if (cont[i] >= 4)
                    res = 4 * (i + 1);
            }
        else if (category < 10)
            res = 30;
        else
            res = 50;
    }
    return res;
}
