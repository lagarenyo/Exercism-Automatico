#include <stdexcept>

using namespace std;

#if !defined(HAMMING_H)
#define HAMMING_H

namespace hamming
{
    int length(const char *str);
    int compute(const char *str1, const char *str2);
}

#endif