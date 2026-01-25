#include "sum_of_multiples.h"

namespace sum_of_multiples
{

    int to(vector<int> multi, int max)
    {
        int res;
        bool is_multi;

        res = 0;
        for (int i = 0; i < max; i++)
        {
            is_multi = false;
            for (auto &element : multi)
                if ((i % element) == 0)
                    is_multi = true;
           if (is_multi)
           res += i;
        }
        return res;
    }

} // namespace sum_of_multiples
