#include "scrabble_score.h"

#include <stdio.h>

unsigned int score(const char *word)
{
    unsigned int res;
    char aux;
    int iterlet;
    int iter;

    res = 0;
    while (*word != '\0')
    {
        aux = *word;
        if ((aux > 96) && (aux < 123))
            aux -= 32;
        iterlet = 0;
        while (let[iterlet] != aux)
            iterlet++;
        iter = 0;
        while (fran[iter] < iterlet)
            iter++;
        res += val[iter];
        word++;
    }
    return res;
}
/*
int main(void)
{
    printf("valor:%i\n", score("abcdefghijklmnopqrstuvwxyz"));
}
*/