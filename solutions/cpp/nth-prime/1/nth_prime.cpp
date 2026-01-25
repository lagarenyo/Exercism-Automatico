#include <stdexcept>

using namespace std;

#include "nth_prime.h"

namespace nth_prime
{
    int nth(int num)
    {
        vector<int> prime;
        int iter1;
        int iter2;
        int locnum;

        if (num > 0)
        {
            prime.resize(num);
            prime[0] = 2;
            iter1 = 1;
            while (iter1 < num)
            {
                locnum = prime[iter1 - 1] + 1;
                iter2 = 0;
                while (iter2 < iter1)
                {
                    if ((locnum % prime[iter2]) == 0)
                    {
                        locnum++;
                        iter2 = 0;
                    }
                    else
                        iter2++;
                }
                prime[iter1] = locnum;
                iter1++;
            }
        }
        else
            throw domain_error("incorrect value");
        return prime[iter1-1];
    }
} // namespace nth_prime
