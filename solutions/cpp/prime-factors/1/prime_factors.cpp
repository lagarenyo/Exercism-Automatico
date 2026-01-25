#include "prime_factors.h"

namespace prime_factors
{

    vector<int> of(int num)
    {
        vector<int> res;
        int it;

        it = 2;
        while (num != 1)
        {
            while ((num % it) != 0)
                it++;
            num /= it;
            res.push_back(it);
        }
        return res;
    }

} // namespace prime_factors
