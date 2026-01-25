#include "pig_latin.h"

static int is_char(char c) { return ((c > 96) && (c < 123)) || ((c > 64) && (c < 91)); }

static int is_vocal(char c) { return (c == 97) || (c == 101) || (c == 105) || (c == 111) || (c == 117) ||
                                     (c == 65) || (c == 69) || (c == 73) || (c == 79) || (c == 85); }

static char *crea_res(const char *cad)
{
    char *res;
    int num_char;
    int num_word;

    res = NULL;
    num_char = 0;
    num_word = 0;
    while (cad[num_char] != '\0')
    {
        if (cad[num_char] == ' ')
            num_word++;
        num_char++;
    }
    num_word++;
    res = malloc(((2 * num_word) + num_char + 1) * (sizeof(char)));
    return res;
}

static int modifi(const char *orig, char *dest, int desp)
{
    int av_orig;
    int av_dest;

    av_dest = 0;
    av_orig = desp;
    while (is_char(orig[av_orig]))
        dest[av_dest++] = orig[av_orig++];
    av_orig = 0;
    while (av_orig < desp)
        dest[av_dest++] = orig[av_orig++];
    dest[av_dest++] = 'a';
    dest[av_dest++] = 'y';
    return av_dest;
}

char *translate(const char *phrase)
{
    char *res;
    char *av_res;
    int aux;

    res = crea_res(phrase);
    av_res = res;
    while (*phrase != '\0')
    {
        while ((*phrase != '\0') && (!is_char(*phrase)))
        {
            *av_res = *phrase;
            av_res++;
            phrase++;
        }
        if (*phrase != '\0')
        {
            if ((is_vocal(*phrase)) || (*phrase == '\0') ||
                (((*phrase == 'x') || (*phrase == 'X')) && ((*(phrase + 1) == 'r') || (*(phrase + 1) == 'R'))) ||
                (((*phrase == 'y') || (*phrase == 'Y')) && ((*(phrase + 1) == 't') || (*phrase + 1) == 'T')))
                aux = modifi(phrase, av_res, 0);
            else
            {
                aux = 1;
                while ((is_char(phrase[aux])) && (!is_vocal(phrase[aux])) && (phrase[aux] != 'y'))
                    aux++;
                if ((phrase[aux] == 'u') && (phrase[aux - 1] == 'q'))
                    aux = modifi(phrase, av_res, aux + 1);
                else
                    aux = modifi(phrase, av_res, aux);
            }
            av_res += aux;
            phrase += aux - 2;
        }
    }
    *av_res = '\0';
    return res;
}