#include "hamming.h"

namespace hamming
{
    int length(const char *str)
    {
        int res;

        res = 0;
        while (str[res])
            res++;
        return res;
    }

    int compute(const char *str1, const char *str2)
    {
        int res, len;

        res = 0;
        len = length(str1);
        if (len == length(str2))
        {
            for (int i = 0; i < len; i++)
            {
                if (str1[i] != str2[i])
                    res++;
            }
        }
        else
            throw domain_error("different lengths");
        return res;
    }

}
