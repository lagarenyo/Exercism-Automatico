#include "pangram.h"

bool is_pangram(const char *sentence)
{
    char elementos[] = "abcdefghijklmnopqrstuvwxyz";
    char marcador = '*';
    char aux;
    int iter;
    iter = 0;
    if (sentence != 0)
    {
        while (sentence[iter] != '\0')
        {
            if ((sentence[iter] >= 65) && (sentence[iter] <= 90))
                aux = sentence[iter] + 32;
            else
                aux = sentence[iter];
            if ((aux >= 97) && (aux <= 122))
                elementos[aux - 97] = marcador;
            iter++;
        }
        iter = 0;
        while ((elementos[iter] == marcador) && (iter < 26))
            iter++;
    }
    return iter == 26;
}
