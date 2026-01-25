#include "clock.h"

clock_t clock_create(int hour, int minute)
{
    clock_t res;

    hour += (minute / 60);
    hour %= 24;
    minute %= 60;
    if (minute < 0)
    {
        minute += 60;
        hour--;
    }
    if (hour < 0)
        hour += 24;
    res.text[0] = (char)((hour / 10) + 48);
    res.text[1] = (char)((hour % 10) + 48);
    res.text[2] = ':';
    res.text[3] = (char)((minute / 10) + 48);
    res.text[4] = (char)((minute % 10) + 48);
    res.text[5] = '\0';
    return res;
}

clock_t clock_add(clock_t clock, int minute_add)
{
    int hour, minute;

    hour = ((clock.text[0] - 48) * 10) + (clock.text[1] - 48);
    minute = ((clock.text[3] - 48) * 10) + (clock.text[4] - 48);
    return clock_create(hour, minute + minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    int hour, minute;

    hour = ((clock.text[0] - 48) * 10) + (clock.text[1] - 48);
    minute = ((clock.text[3] - 48) * 10) + (clock.text[4] - 48);
    return clock_create(hour, minute - minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b)
{
    return ((a.text[0] == b.text[0]) & (a.text[1] == b.text[1]) & (a.text[3] == b.text[3]) & (a.text[4] == b.text[4]));
}
