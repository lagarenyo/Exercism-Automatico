#include "kindergarten_garden.h"

static const char *students[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Fred",
                                 "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry", 0};

static int compare(const char *nom1, const char *nom2)
{
    int res;

    res = 0;
    while ((*nom1 == *nom2) && (*nom1 != '\0') && (*nom2 != '\0'))
    {
        nom1++;
        nom2++;
    }
    if ((*nom1 == '\0') && (*nom2 == '\0'))
        res = 1;
    return res;
}

static plant_t asig(char c)
{
    plant_t res;

    if (c == 'C')
        res = CLOVER;
    if (c == 'G')
        res = GRASS;
    if (c == 'R')
        res = RADISHES;
    if (c == 'V')
        res = VIOLETS;
    return res;
}

plants_t plants(const char *diagram, const char *student)
{
    plants_t res;
    int iter;
    int pos;

    iter = 0;
    pos = 0;
    while ((students[iter] != 0) && !compare(students[iter], student))
        iter++;
    while (diagram[pos] != '\n')
        pos++;
    pos++;
    res.plants[0] = asig(diagram[2 * iter]);
    res.plants[1] = asig(diagram[(2 * iter) + 1]);
    res.plants[2] = asig(diagram[(2 * iter) + pos]);
    res.plants[3] = asig(diagram[(2 * iter) + pos + 1]);
    return res;
}