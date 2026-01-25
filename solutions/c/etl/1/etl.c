#include "etl.h"

int convert(const legacy_map *input, const size_t input_len, new_map **output)
{
    int cont;
    int iter;
    int buf[27];

    cont = 0;
    buf[26] = '\0';
    for (int i = 0; i < 26; i++)
        buf[i] = 0;
    for (size_t i = 0; i < input_len; i++)
    {
        iter = 0;
        while (input[i].keys[iter] != '\0')
        {
            cont++;
            iter++;
        }
    }
    for (size_t i = 0; i < input_len; i++)
    {
        iter = 0;
        while (input[i].keys[iter] != '\0')
        {
            buf[input[i].keys[iter] - 65] = input[i].value;
            iter++;
        }
    }
    *output = malloc(cont * sizeof(new_map));
    iter = 0;
    for (int i = 0; i < 26; i++)
    {
        if (buf[i] != 0)
        {
            (*output)[iter].key = i + 97;
            (*output)[iter].value = buf[i];
            iter++;
        }
    }
    return cont;
}