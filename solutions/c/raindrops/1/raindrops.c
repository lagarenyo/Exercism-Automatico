#include "raindrops.h"

static void digitos(char result[], int drops)
{
    int pos;
    int aux;

    pos = 0;
    aux = drops;
    while (aux > 0)
    {
        aux /= 10;
        pos++;
    }
    result[pos--] = '\0';
    aux = drops;
    while (pos >= 0)
    {
        result[pos] = 48 + (aux % 10);
        aux /= 10;
        pos--;
    }
}

static void cadena(char result[], char *data)
{
    int pos;
    int i;

    pos = 0;
    for (i = 1; i < 4; i++)
    {
        if (data[i] != '0')
        {
            result[pos++] = 'P';
            result[pos++] = 'l';
            result[pos++] = data[i];
            result[pos++] = 'n';
            result[pos++] = 'g';
        }
    }
    result[pos] = '\0';
}

void convert(char result[], int drops)
{
    char data[5];
    int i;

    data[4] = '\0';
    data[0] = 0;
    for (i = 1; i < 4; i++)
        data[i] = '0';
    if ((drops % 3) == 0)
    {
        data[1] = 'i';
        data[0]++;
    }
    if ((drops % 5) == 0)
    {
        data[2] = 'a';
        data[0]++;
    }
    if ((drops % 7) == 0)
    {
        data[3] = 'o';
        data[0]++;
    }
    (data[0] == 0) ? digitos(result, drops) : cadena(result, data);
}
