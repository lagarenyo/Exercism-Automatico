#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int val)
{
    allergen_list_t alerg;

    alerg = get_allergens(val);
    return alerg.allergens[allergen];
}

allergen_list_t get_allergens(int value)
{
    allergen_list_t res;
    int values[ALLERGEN_COUNT + 1];
    int iter;

    res.count = 0;
    values[0] = 1;
    for (iter = 1; iter <= ALLERGEN_COUNT; iter++)
        values[iter] = 2 * values[iter - 1];
    value %= values[ALLERGEN_COUNT];
    for (iter = ALLERGEN_COUNT - 1; iter >= 0; iter--)
    {
        if (value >= values[iter])
        {
            res.count++;
            res.allergens[iter] = true;
            value -= values[iter];
        }
        else
            res.allergens[iter] = false;
    }
    return res;
}