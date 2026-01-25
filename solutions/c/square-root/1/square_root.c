#include "square_root.h"

int	square_root(int num)
{
	int	res;
	int	prev;

	res = num;
	prev = 0;
	while (prev != res)
	{
		prev = res;
		res = ((num / res) + res) / 2;
	}
	return (res);
}
