#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include <stddef.h>

#include <stdlib.h>

char **annotate(const char **minefield, const size_t rows);
void free_annotation(char **annotation);

#endif
