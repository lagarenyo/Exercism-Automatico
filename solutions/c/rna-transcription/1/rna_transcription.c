#include "rna_transcription.h"

static int leng(const char *dna)
{
    int leng;

    leng = 0;
    while (dna[leng] != '\0')
        leng++;
    leng++;
    return leng;
}

char *to_rna(const char *dna)
{
    const char correlacion[2][4] = {{'G', 'C', 'T', 'A'}, {'C', 'G', 'A', 'U'}};
    char *res;
    int longitud;
    int i;
    int j;

    longitud = leng(dna);
    res = malloc(longitud * sizeof(char));

    longitud--;
    i = 0;
    while (i < longitud)
    {
        for (j = 0; j < 4; j++)
        {
            if (dna[i] == correlacion[0][j])
            {
                res[i] = correlacion[1][j];
                j = 5;
            }
        }
        i++;
    }
    res[longitud] = '\0';
    return res;
}
