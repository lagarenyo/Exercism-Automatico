#include "bob.h"

#define N_RESPON 5

static char *respon[N_RESPON] = {
    "Sure.", "Whoa, chill out!",
    "Calm down, I know what I'm doing!", "Fine. Be that way!", "Whatever."};

char *hey_bob(char *greeting)
{
    int res;
    char m;
    char p;
    char v;

    res = 0;
    m = 2;
    p = 0;
    v = 1;
    while (*greeting != '\0')
    {
        if ((*greeting != ' ') && (*greeting != '\n') && (*greeting != '\t') && (*greeting != '\r'))
        {
            v = 0;
            p = (*greeting != '?') ? 0 : 1;
            if ((m != 0) && (*greeting > 64) && (*greeting < 91))
                m = 1;
            if ((m != 0) && (*greeting > 96) && (*greeting < 123))
                m = 0;
        }
        greeting++;
    }
    res = 4;
    res = ((m != 1) && (p == 1)) ? 0 : res;
    res = ((m == 1) && (p == 0)) ? 1 : res;
    res = ((m == 1) && (p == 1)) ? 2 : res;
    res = (v == 1) ? 3 : res;
    return respon[res];
}