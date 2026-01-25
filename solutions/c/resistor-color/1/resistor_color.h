#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H

typedef enum
{
  BLACK,
  BROWN,
  RED,
  ORANGE,
  YELLOW,
  GREEN,
  BLUE,
  VIOLET,
  GREY,
  WHITE
} resistor_band_t;

static resistor_band_t all_colors[] = {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE};
int color_code(resistor_band_t code);
const resistor_band_t *colors();

#endif
