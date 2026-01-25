#include "anagram.h"

static int identic(const char origen[static MAX_STR_LEN], char destino[static MAX_STR_LEN])
{
    int res;
    int iter;

    res = 1;
    iter = 0;
    while ((res) && (origen[iter] != '\0'))
    {
        res = (origen[iter] == destino[iter]) ? 1 : 0;
        iter++;
    }
    return res;
}

static int up(const char origen[static MAX_STR_LEN], char destino[static MAX_STR_LEN])
{
    int res;

    res = 0;
    while (origen[res] != '\0')
    {
        destino[res] = ((origen[res] > 96) && (origen[res] < 123)) ? (origen[res] - 32) : origen[res];
        res++;
    }
    destino[res] = '\0';
    res++;
    return res;
}

void find_anagrams(const char *subject, struct candidates *candidates)
{
    char s[MAX_STR_LEN];
    char c[MAX_STR_LEN];
    int ls;
    int lc;
    int iter;

    ls = 0;
    lc = 0;
    ls = up(subject, s);
    for (size_t i = 0; i < candidates->count; i++)
    {
        lc = up(candidates->candidate[i].word, c);
        if ((ls != lc) || (identic(s, c)))
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
        else
        {
            lc = 0;
            for (int j = 0; j < ls; j++)
            {
                iter = 0;
                while (iter < ls)
                {
                    if ((s[j] == c[iter]))
                    {
                        c[iter] = 0;
                        iter = ls;
                        lc++;
                    }
                    else
                        iter++;
                }
            }
            candidates->candidate[i].is_anagram = (ls == lc) ? IS_ANAGRAM : NOT_ANAGRAM;
        }
    }
}