#include "clock.h"

namespace date_independent
{
    void clock::calculus(int position, int offset)
    {
        int aux;

        aux = position + offset;
        aux %= 1440;
        if (aux < 0)
            aux += 1440;
        this->hour = aux / 60;
        this->minute = aux % 60;
    }

    bool clock::operator==(const clock &dat) const
    {
        return hour == dat.hour and minute == dat.minute;
    }

    bool clock::operator!=(const clock &dat) const
    {
        return hour != dat.hour or minute != dat.minute;
    }

    clock::operator std::string() const
    {
        return (hour < 10 ? "0" : "") + std::to_string(hour) +
               ":" + (minute < 10 ? "0" : "") + std::to_string(minute);
    }

    clock clock::at(int hour, int minute)
    {
        clock res;
        res.calculus((hour * 60), minute);
        return res;
    }

    clock clock::plus(int add)
    {
        this->calculus((this->hour * 60) + minute, add);
        return *this;
    }
}
