#include "nucleotide_count.h"

struct dato
{
    char nuc;
    int cant;
};
char *count(const char *dna_strand)
{

    struct dato dat[4];
    int aux1, aux2, iter;
    char *res;

    aux1 = 0;
    dat[0].nuc = 'A';
    dat[1].nuc = 'C';
    dat[2].nuc = 'G';
    dat[3].nuc = 'T';
    for (int i = 0; i < 4; i++)
        dat[i].cant = 0;
    while (((*dna_strand) != '\0') && !aux1)
    {
        aux1 = 1;
        for (int i = 0; i < 4; i++)
        {
            if (dat[i].nuc == *dna_strand)
            {
                dat[i].cant++;
                aux1 = 0;
            }
        }
        dna_strand++;
    }
    iter = 0;
    if (!aux1)
    {
        res = malloc(sizeof(char) * 24);
        for (int i = 0; i < 4; i++)
        {
            res[iter++] = dat[i].nuc;
            res[iter++] = ':';
            aux1 = dat[i].cant;
            aux2 = 1;
            while (aux1 > 9)
            {
                aux1 /= 10;
                aux2 *= 10;
            }
            aux1 = dat[i].cant;
            while (aux1 > 9)
            {
                res[iter++] = (aux1 / aux2) + 48;
                aux1 %= aux2;
                aux2 /= 10;
            }
            res[iter++] = aux1 + 48;
            res[iter++] = ' ';
        }
        iter--;
    }
    else
        res = malloc(sizeof(char));
    res[iter] = '\0';

    printf("res:%s\n", res);

    return res;
}
