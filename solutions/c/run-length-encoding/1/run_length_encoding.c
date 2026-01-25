#include "run_length_encoding.h"

char *encode(const char *text)
{
    char *res;
    int av_orig;
    int av_dest;
    int sub;

    res = malloc(LONGIT * sizeof(char));
    av_orig = 0;
    av_dest = 0;
    while (text[av_orig] != '\0')
    {
        sub = 1;
        if (((text[av_orig] >= 'a') && (text[av_orig] <= 'z')) ||
            ((text[av_orig] >= 'A') && (text[av_orig] <= 'Z')) ||
            (text[av_orig] == ' '))
        {
            while ((text[av_orig + sub] != '\0') && (text[av_orig] == text[av_orig + sub]))
                sub++;
            if (sub > 1)
            {
                if (sub > 9)
                {
                    res[av_dest] = (sub / 10) + 48;
                    av_dest++;
                }
                res[av_dest] = (sub % 10) + 48;
                av_dest++;
            }
        }
        res[av_dest] = text[av_orig];
        av_dest++;
        av_orig += sub;
    }
    res[av_dest] = '\0';
    return res;
}

char *decode(const char *data)
{
    char *res;
    int av_orig;
    int av_dest;
    int num;

    res = malloc(LONGIT * sizeof(char));
    av_orig = 0;
    av_dest = 0;
    while (data[av_orig] != '\0')
    {
        num = 1;
        if ((data[av_orig] >= '0') && (data[av_orig] <= '9'))
        {
            if ((data[av_orig + 1] >= '0') && (data[av_orig + 1] <= '9'))
            {
                num = ((data[av_orig] - 48) * 10) + (data[av_orig + 1] - 48);
                av_orig += 2;
            }
            else
            {
                num = data[av_orig] - 48;
                av_orig++;
            }
        }
        for (int i = 0; i < num; i++)
        {
            res[av_dest] = data[av_orig];
            av_dest++;
        }
        av_orig++;
    }
    res[av_dest] = '\0';
    return res;
}
