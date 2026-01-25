#include "grains.h"

uint64_t	square(uint8_t index)
{
	uint64_t	res;

	res = index > 0 ? 1 : 0;
	for (uint8_t i = 2; i <= index; i++)
		res *= 2;
	return (res);
}

uint64_t	total(void)
{
	return (square(65) - 1);
}