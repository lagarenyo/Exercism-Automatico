#include "binary_search.h"

namespace binary_search
{
    int find(vector<int> data, int target)
    {
        int res;
        int init;
        int end;
        int cent;

        init = 0;
        end = data.size() - 1;
        if (end < 0)
            throw domain_error("");
        res = -1;
        if (data[init] == target)
            res = init;
        else if (data[end] == target)
            res = end;
        while (res < 0)
        {
            if (end == (init + 1))
                throw domain_error("");
            else
            {
                cent = ((end - init) / 2) + init;
                if (data[cent] == target)
                    res = cent;
                else if (target < data[cent])
                    end = cent;
                else
                    init = cent;
            }
        }
        return res;
    }
}
