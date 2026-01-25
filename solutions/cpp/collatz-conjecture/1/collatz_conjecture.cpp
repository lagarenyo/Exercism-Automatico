#include "collatz_conjecture.h"

namespace collatz_conjecture
{
    int steps(int num)
    {
        int res;
        div_t resdiv;

        res = 0;
        while (num > 1)
        {
            resdiv = div(num, 2);
            if (resdiv.rem == 0)
                num /= 2;
            else
                num = (num * 3) + 1;
            res++;
        }
        if (num != 1)
            throw domain_error("invalid argument");
        return res;
    }
} // namespace collatz_conjecture
