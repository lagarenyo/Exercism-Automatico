#include "pangram.h"

namespace pangram
{
    bool is_pangram(string cad)
    {
        char let[26];
        bool res;

        for (int i = 0; i < 26; i++)
            let[i] = 0;
        for (int i = 0; i < (int)cad.length(); i++)
            if (isalpha(cad[i]))
                let[toupper(cad[i]) - 65] = 1;
        res = true;
        for (int i = 0; i < 26; i++)
            res = res && let[i];
        return res;
    }

} // namespace pangram
