#include "protein_translation.h"

proteins_t proteins(const char *const rna)
{
    proteins_t res;
    const char *aux;
    int cont;
    bool st;

    cont = 0;
    res.valid = true;
    aux = rna;
    st = false;
    while ((res.valid) && (*aux != '\0') && !st)
    {
        if ((*aux == 'A') && (*(aux + 1) == 'U') && (*(aux + 2) == 'G'))
        {
            res.proteins[cont] = Methionine;
            cont++;
            res.valid = true;
            aux += 2;
        }
        else if (*aux == 'U')
        {
            aux++;
            switch (*aux)
            {
            case 'A':
            {
                aux++;
                if (((*aux) == 'A') || ((*aux) == 'G'))
                    st = true;
                else if (((*aux) == 'C') || ((*aux) == 'U'))
                    res.proteins[cont++] = Tyrosine;
                else
                    res.valid = false;
                break;
            }
            case 'C':
            {
                aux++;
                if (((*aux) == 'A') || ((*aux) == 'G') || ((*aux) == 'C') || ((*aux) == 'U'))
                    res.proteins[cont++] = Serine;
                else
                    res.valid = false;
                break;
            }
            case 'G':
            {
                aux++;
                if ((*aux) == 'A')
                    st = true;
                else if (((*aux) == 'C') || ((*aux) == 'U'))
                    res.proteins[cont++] = Cysteine;
                else if ((*aux) == 'G')
                    res.proteins[cont++] = Tryptophan;
                else
                    res.valid = false;
                break;
            }
            case 'U':
            {
                aux++;
                if (((*aux) == 'A') || ((*aux) == 'G'))
                    res.proteins[cont++] = Leucine;
                else if (((*aux) == 'C') || ((*aux) == 'U'))
                    res.proteins[cont++] = Phenylalanine;
                else
                    res.valid = false;
                break;
            }
            default:
                res.valid = false;
            }
        }
        else
            res.valid = false;
        aux++;
    }
    res.count = cont;
    return res;
}
