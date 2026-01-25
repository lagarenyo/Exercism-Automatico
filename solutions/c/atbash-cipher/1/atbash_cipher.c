#include "atbash_cipher.h"

static char evalua(char c)
{
    char res;

    res = 0;
    if ((c >= '0') && (c <= '9'))
        res = 1;
    if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
        res = (c <= 'Z') ? c + 32 : c;
    return res;
}

char *atbash_encode(const char *input)
{
    char *res;
    char val;
    int av_orig;
    int av_dest;

    av_orig = 0;
    while (input[av_orig] != '\0')
        av_orig++;
    res = malloc((av_orig + (av_orig / 5) + 1) * sizeof(char));
    av_orig = 0;
    av_dest = 0;
    while (input[av_orig] != '\0')
    {
        if ((input[av_orig + 1] != '\0') && (((av_dest + 1) % 6) == 0))
            res[av_dest++] = ' ';
        val = evalua(input[av_orig]);
        if (val != 0)
        {
            res[av_dest] = (val == 1) ? input[av_orig] : 219 - val;
            av_dest++;
        }
        av_orig++;
    }
    res[av_dest] = '\0';
    return res;
}

char *atbash_decode(const char *input)
{

    char *res;
    char val;
    int av_orig;
    int av_dest;

    av_orig = 0;
    while (input[av_orig] != '\0')
        av_orig++;
    res = malloc((av_orig + 1) * sizeof(char));
    av_orig = 0;
    av_dest = 0;
    while (input[av_orig] != '\0')
    {
        val = evalua(input[av_orig]);
        if (val != 0)
            res[av_dest++] = (val == 1) ? input[av_orig] : 219 - val;
        av_orig++;
    }
    res[av_dest] = '\0';
    return res;
}
