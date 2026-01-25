#include "beer_song.h"

static int addnum(int num, char *cad)
{
    int res;

    res = 0;
    if (num > 9)
    {
        *cad = (num / 10) + 48;
        *(cad + 1) = (num % 10) + 48;
        res++;
    }
    else
        *cad = num + 48;
    res++;
    return res;
}
static int addtext(const char *text, char *cad)
{
    int res;

    res = 0;
    while ((*text) != '\0')
    {
        *cad = *text;
        cad++;
        text++;
        res++;
    }
    return res;
}

void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{
    char *iter;

    iter = *song;
    while (take_down != 0)
    {
        if (start_bottles > 0)
        {
            iter += addnum(start_bottles, iter);
            if (start_bottles != 1)
                iter += addtext(" bottles", iter);
            else
                iter += addtext(" bottle", iter);

            iter += addtext(" of beer on the wall, ", iter);
            iter += addnum(start_bottles, iter);
            if (start_bottles != 1)
                iter += addtext(" bottles", iter);
            else
                iter += addtext(" bottle", iter);
            iter += addtext(" of beer.", iter);
            *iter = '\0';
            song++;
            iter = *song;
            iter += addtext("Take ", iter);
            if (start_bottles > 1)
                iter += addtext("one", iter);
            else
                iter += addtext("it", iter);
            iter += addtext(" down and pass it around, ", iter);
            start_bottles--;
            if (start_bottles > 0)
                iter += addnum(start_bottles, iter);
            else
                iter += addtext("no more", iter);
            if (start_bottles != 1)
                iter += addtext(" bottles", iter);
            else
                iter += addtext(" bottle", iter);
            iter += addtext(" of beer on the wall.", iter);
            *iter = '\0';
        }
        else
        {
            iter += addtext("No more bottles of beer on the wall, no more bottles of beer.", iter);
            song++;
            iter = *song;
            iter += addtext("Go to the store and buy some more, 99 bottles of beer on the wall.", iter);
        }
        take_down--;
        if (take_down != 0)
        {
            song++;
            **song = '\0';
            song++;
            iter = *song;
        }
    }
}