#include "reverse_string.h"

namespace reverse_string
{
    string reverse_string(string cad)
    {
        int n;
        int i;
        int j;
        char aux;

        n = cad.length();
        j = n - 1;
        n /= 2;
        for (i = 0; i < n; i++, j--)
        {
            aux = cad[i];
            cad[i] = cad[j];
            cad[j] = aux;
        }
        return cad;
    }
}
