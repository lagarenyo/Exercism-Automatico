#include "sieve.h"

namespace sieve
{
    vector<int> primes(int num)
    {
        vector<bool> rank;
        vector<int> res;
        int iter;
        int mark;
        int max;

        if (num > 1)
        {
            max = num + 1;
            rank.resize(num);
            for (int i = 2; i <= max; i++)
                rank[i] = true;
            iter = 2;
            while (iter <= max)
            {
                if (rank[iter])
                {
                    mark = iter + iter;
                    while (mark <= max)
                    {
                        rank[mark] = false;
                        mark += iter;
                    }
                }
                iter++;
            }
            for (int i = 2; i < max; i++)
                if (rank[i])
                    res.push_back(i);
        }
        return res;
    }
} // namespace sieve
