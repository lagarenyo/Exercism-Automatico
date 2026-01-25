#include "series.h"

namespace series
{
    vector<string> slice(string str, int num)
    {
        vector<string> res;
        int head;
        int strleng;

        strleng = str.length();
        if ((num < 1) || (num > strleng))
            throw std::domain_error("");
        else
        {
            head = 0;
            while ((head + num) <= strleng)
                res.push_back(str.substr(head++, num));
        }
        return res;
    }
}
