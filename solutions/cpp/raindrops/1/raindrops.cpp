#include "raindrops.h"

namespace raindrops
{

    string convert(int num)
    {
        string res;
        int mod[3];
        mod[0] = num % 3;
        mod[1] = num % 5;
        mod[2] = num % 7;
        if (!mod[0])
            res += "Pling";
        if (!mod[1])
            res += "Plang";
        if (!mod[2])
            res += "Plong";
        if ((mod[0]) && (mod[1]) && (mod[2]))
            res = to_string(num);
        return res;
    }

} // namespace raindrops
