#include "resistor_color.h"

const resistor_band_t all_colors[] = {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE};

int color_code(resistor_band_t code) { return code; }

const resistor_band_t *colors()
{
    return all_colors;
}
