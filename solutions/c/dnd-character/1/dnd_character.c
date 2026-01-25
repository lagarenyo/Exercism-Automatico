#include "dnd_character.h"

int ability(void)
{
    int tirada[4];
    int i;
    int j;

    j = 0;
    for (i = 0; i < 4; i++)
    {
        tirada[i] = (rand() % 6) + 1;
        if (tirada[i] < tirada[j])
            j = i;
    }
    tirada[j] = 0;
    return tirada[0] + tirada[1] + tirada[2] + tirada[3];
}

int modifier(int score)
{
    int res;
    int modul;

    res = score - 10;
    modul = res % 2;
    res /= 2;
    if (modul < 0)
        res += modul;
    return res;
}

dnd_character_t make_dnd_character(void)
{
    dnd_character_t res;

    res.strength = ability();
    res.dexterity = ability();
    res.constitution = ability();
    res.intelligence = ability();
    res.wisdom = ability();
    res.charisma = ability();
    res.hitpoints = 10 + modifier(res.constitution);
    return res;
}
