#include "atbash_cipher.h"

namespace atbash_cipher
{
    string encode(string str)
    {
        string res;
        int cont;

        cont = 0;
        for (char c : str)
        {
            if (isalnum(c))
            {
                if (cont > 4)
                {
                    res += ' ';
                    cont = 0;
                }
                if (isalpha(c))
                    c = 219 - tolower(c);
                res += c;
                cont++;
            }
        }
        return res;
    }

    string decode(string str)
    {
        string res;

        for (char c : str)
        {
            if (isalnum(c))
            {
                if (isalpha(c))
                    c = 219 - tolower(c);
                res += c;
            }
        }
        return res;
    }
}