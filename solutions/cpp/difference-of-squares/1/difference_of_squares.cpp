#include "difference_of_squares.h"

namespace difference_of_squares
{
    int square_of_sum(int num)
    {
        int res;

        res = 0;
        for (int i = 0; i <= num; i++)
            res += i;
        res *= res;
        return res;
    }
    int sum_of_squares(int num)
    {
        int res;

        res = 0;
        for (int i = 0; i <= num; i++)
            res += (i * i);
        return res;
    }
    int difference(int num)
    {
        return square_of_sum(num) - sum_of_squares(num);
    }
} // namespace difference_of_squares
