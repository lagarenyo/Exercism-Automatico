#include "phone_number.h"

char *phone_number_clean(const char *input)
{
    char *res;
    int count;
    int iter;
    char aux[12];

    res = malloc(11 + sizeof(char));
    count = 0;
    iter = 0;
    aux[11] = '\0';
    res[10] = '\0';
    for (int i = 0; i < 10; i++)
        res[i] = '0';
    while ((count < 11) && (input[iter] != '\0'))
    {
        if ((input[iter] >= '0') && (input[iter] <= '9'))
            aux[count++] = input[iter];
        iter++;
    }
    iter = 0;
    if ((count == 11) && (aux[iter] == '1'))
        iter++;
    if (((count == 10) || (iter == 1)) && (aux[iter] > '1') && (aux[iter + 3] > '1'))
        for (int i = 0; i < 10; i++)
            res[i] = aux[iter++];
    return res;
}
