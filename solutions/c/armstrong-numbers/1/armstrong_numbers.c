#include "armstrong_numbers.h"

bool	is_armstrong_number(int candidate)
{
	int digit;
	int sum;
	int num;
	int leng;

	sum = 0;
	if (candidate != 0)
	{
		num = candidate;
		leng = floor(log10(abs(candidate))) + 1;
		while ((num > 9) && (sum < candidate))
		{
			digit = num % 10;
			num /= 10;
			sum += pow(digit, leng);
		}
		sum += (int)pow(num, leng);
	}
	return (candidate == sum);
}