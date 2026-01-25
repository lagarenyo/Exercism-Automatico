#include "trinary.h"

namespace trinary
{
    int to_decimal(string str)
    {
        int res;
        int pos;
        int iter;
        bool fault;

        res = 0;
        fault = false;
        iter = str.length() - 1;
        pos = 0;
        while ((iter >= 0) && (!fault))
        {
            if (str[iter] == '2')
                res += 2 * (pow(3, pos));
            else if (str[iter] == '1')
                res += 1 * (pow(3, pos));
            else if (str[iter] != '0')
                fault = true;
            iter--;
            pos++;
        }
        if (fault)
            res = 0;
        return res;
    }

}
