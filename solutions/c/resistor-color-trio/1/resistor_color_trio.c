#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t codigo[])
{
    resistor_value_t res;

    if (codigo[1] == BLACK)
        codigo[2]++;
    if (codigo[2] < 3)
    {
        res.value = ((10 * codigo[0]) + codigo[1]) * pow(10, codigo[2]);
        res.unit = OHMS;
    }
    else if ((codigo[2] > 2) && (codigo[2] < 6))
    {
        res.value = ((10 * codigo[0]) + codigo[1]) * pow(10, codigo[2] - 3);
        res.unit = KILOOHMS;
    }
    else if ((codigo[2] > 5) && (codigo[2] < 9))
    {
        res.value = ((10 * codigo[0]) + codigo[1]) * pow(10, codigo[2] - 6);
        res.unit = MEGAOHMS;
    }
    else
    {
        res.value = (10 * codigo[0]) + codigo[1];
        res.unit = GIGAOHMS;
    }
    if (codigo[1] == BLACK)
        res.value = codigo[0];
    return res;
}
