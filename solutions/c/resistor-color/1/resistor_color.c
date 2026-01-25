#include "resistor_color.h"

int color_code(resistor_band_t code) { return code; }

const resistor_band_t *colors()
{
    return all_colors;
}
