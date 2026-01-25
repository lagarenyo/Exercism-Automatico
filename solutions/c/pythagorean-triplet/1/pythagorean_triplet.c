#include "pythagorean_triplet.h"

triplets_t *triplets_with_sum(uint16_t sum)
{
    triplets_t *res;
    triplet_t buf[15];
    int cont;
    int aux;
    int c;

    cont = 0;
    for (int i = 2; i < (sum / 2); i++)
    {
        aux = sum - i;
        for (int j = (i + 1); j < aux; j++)
        {
            c = aux - j;
            if (((i + j + c) == sum) && (c > j))
            {
                if (((i * i) + (j * j)) == (c * c))
                {
                    buf[cont].a = i;
                    buf[cont].b = j;
                    buf[cont].c = c;
                    cont++;
                }
            }
        }
    }
    res = malloc(sizeof(triplets_t));
    res->count = cont;
    res->triplets = malloc(cont * sizeof(triplet_t));
    for (int i = 0; i < cont; i++)
    {
        res->triplets[i].a = buf[i].a;
        res->triplets[i].b = buf[i].b;
        res->triplets[i].c = buf[i].c;
    }
    return res;
}

void free_triplets(triplets_t *trip)
{
    free(trip->triplets);
    free(trip);
}
