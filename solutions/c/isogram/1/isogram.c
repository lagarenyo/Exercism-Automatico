#include "isogram.h"

bool is_isogram(const char phrase[])
{
    int iter;
    int pivot;
    bool res;

    res = true;
    pivot = 0;
    while ( phrase[pivot] != '\0' && res)
    {
        iter = pivot + 1;
        while (phrase[iter] != '\0' && res)
            phrase[pivot] != phrase[iter] ? iter++ : (res = false);
        pivot++;
    }
    return res;
}
