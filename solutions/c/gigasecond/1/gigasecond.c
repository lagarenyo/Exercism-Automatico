#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size)
{
    time_t dato = input + 1000000000;
    struct tm *conversion;
    conversion = gmtime(&dato);
    strftime(output, size, "%Y-%m-%d %H:%M:%S", conversion);
}