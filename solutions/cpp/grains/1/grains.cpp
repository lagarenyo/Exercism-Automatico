#include "grains.h"

namespace grains
{
    unsigned long long square(int pos)
    {
        unsigned long long res;
        
        if (pos == 1)
            res = 1;
        else
        {
            res = 2;
            while (--pos > 1)
                res *= 2;
        }
        return res;
    }

    unsigned long long total()
    {
        return (square(65) - 1);
    }

} // namespace grains
