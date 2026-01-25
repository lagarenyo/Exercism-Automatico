#include "meetup.h"

static const char *q_dia[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
static const char *q_semana[6] = {"first", "second", "third", "fourth", "teenth", "last"};

static int cmp_cadena(const char *a, const char *b)
{
    while ((*a != '\0') && (*b != '\0') && (*a == *b))
    {
        a++;
        b++;
    }
    return (*a == *b);
}

static int identif(const char *my_dat, const char **dat)
{
    int res;

    res = 0;
    while ((dat[res]) && (!cmp_cadena(dat[res], my_dat)))
        res++;
    return res;
}

static int dia_semana(unsigned int year, unsigned int month, unsigned int day)
{
    unsigned a;
    unsigned b;

    if (month <= 2)
    {
        month += 10;
        year -= 1;
    }
    else
        month -= 2;
    a = year % 100;
    b = year / 100;
    return (700 + ((26 * month - 2) / 10) + day + a + a / 4 + b / 4 - 2 * b) % 7;
}

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week, const char *day_of_week)
{

    int aux;
    int num_semana;
    int aj;
    int dia;
    int dia_x;
    int dia_y;

    num_semana = identif(week, q_semana);
    dia = identif(day_of_week, q_dia);
    if (num_semana < 4)
        aj = 1 + (num_semana * 7);
    else if (num_semana == 4)
        aj = 13;
    else
    {
        dia_x = dia_semana(year, month, 28);
        dia_y = dia_semana(year, month + 1, 1);
        if (dia_x < dia_y)
            aj = dia_y - dia_x;
        else
            aj = (7 - dia_x) + dia_y;
        aj = 28 - (7 - aj);
    }
    aux = dia_semana(year, month, aj);
    if (aux < dia)
        aj += dia - aux;
    else if (dia < aux)
        aj += 7 - aux + dia;
    return aj;
}