#include "darts.h"

uint8_t score(coordinate_t coordenada)
{
    uint8_t res;
    double_t valor;

    res = 0;
    valor = sqrt(pow(coordenada.x, 2) + pow(coordenada.y, 2));
    if (valor <= 1)
        res = 10;
    else if (valor <= 5)
        res = 5;
    else if (valor <= 10)
        res = 1;
    return res;
}