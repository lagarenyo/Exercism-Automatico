#include "word_count.h"

static void init_words(word_count_word_t *words)
{
    for (int i = 0; i < MAX_WORDS; i++)
    {
        words[i].text[0] = '\0';
        words[i].count = 0;
    }
}

static int compare_words(char a[MAX_WORD_LENGTH + 1], char b[MAX_WORD_LENGTH + 1])
{
    int iter;

    iter = 0;
    while ((a[iter] != '\0') && (b[iter] != '\0') && (a[iter] == b[iter]))
        iter++;
    return (a[iter] == b[iter]);
}

static int is_char(char c)
{
    return (((c > 64) && (c < 91)) || ((c > 96) && (c < 123)) || ((c > 47) && (c < 58)));
}

int count_words(const char *sentence, word_count_word_t *words)
{
    char aux[MAX_WORD_LENGTH + 1];
    int iter;
    int av;
    int res;

    init_words(words);
    aux[MAX_WORD_LENGTH] = '\0';
    res = 0;
    while ((!res) && (*sentence != '\0'))
    {
        while ((*sentence != '\0') && (!is_char(*sentence)))
            sentence++;
        av = 0;
        while ((!res) && (*sentence != '\0') &&
               (is_char(*sentence) || ((*sentence == '\'') && is_char(*(sentence + 1)))))
        {
            aux[av] = (((*sentence > 64) && (*sentence < 91))) ? *sentence + 32 : *sentence;
            av++;
            sentence++;
            if (av == MAX_WORD_LENGTH)
                res = EXCESSIVE_LENGTH_WORD;
        }
        aux[av] = '\0';
        if (!res && (av > 0))
        {
            iter = 0;
            while ((words[iter].count != 0) && (!compare_words(words[iter].text, aux)))
                iter++;
            if (iter == MAX_WORDS)
                res = EXCESSIVE_LENGTH_WORD;
            if (!res)
            {
                if ((words[iter].count == 0))
                {
                    av = 0;
                    while (aux[av] != '\0')
                    {
                        words[iter].text[av] = aux[av];
                        av++;
                    }
                    words[iter].text[av] = aux[av];
                }
                words[iter].count++;
                sentence += (*sentence != '\0') ? 1 : 0;
            }
        }
    }
    if (!res)
    {
        iter = 0;
        while (words[iter].count != 0)
            iter++;
        res = iter;
    }
    return res;
}