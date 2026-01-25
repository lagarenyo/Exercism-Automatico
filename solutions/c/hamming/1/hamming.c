#include "hamming.h"

int	compute(const char *lhs, const char *rhs)
{
	int	res;

	res = -1;
	if (strlen(lhs) == strlen(rhs))
	{
		res = 0;
		while (*lhs != '\0')
		{
			res += (*lhs != *rhs) ? 1 : 0;
            lhs++;
            rhs++;
		}
	}
	return (res);
}
