#include "meetup.h"

using namespace boost::gregorian;

namespace meetup
{
    date scheduler::monteenth() const
    {
        return next_weekday(date(this->year, this->month, 13), greg_weekday(Monday));
    }

    date scheduler::tuesteenth() const
    {

        return next_weekday(date(this->year, this->month, 13), greg_weekday(Tuesday));
    }

    date scheduler::wednesteenth() const
    {
        return next_weekday(date(this->year, this->month, 13), greg_weekday(Wednesday));
    }

    date scheduler::thursteenth() const
    {
        return next_weekday(date(this->year, this->month, 13), greg_weekday(Thursday));
    }

    date scheduler::friteenth() const
    {
        return next_weekday(date(this->year, this->month, 13), greg_weekday(Friday));
    }

    date scheduler::saturteenth() const
    {
        return next_weekday(date(this->year, this->month, 13), greg_weekday(Saturday));
    }

    date scheduler::sunteenth() const
    {
        return next_weekday(date(this->year, this->month, 13), greg_weekday(Sunday));
    }

    date scheduler::first_monday() const
    {
        return next_weekday(date(this->year, this->month, 1), greg_weekday(Monday));
    }

    date scheduler::first_tuesday() const
    {
        return next_weekday(date(this->year, this->month, 1), greg_weekday(Tuesday));
    }

    date scheduler::first_wednesday() const
    {
        return next_weekday(date(this->year, this->month, 1), greg_weekday(Wednesday));
    }

    date scheduler::first_thursday() const
    {
        return next_weekday(date(this->year, this->month, 1), greg_weekday(Thursday));
    }

    date scheduler::first_friday() const
    {
        return next_weekday(date(this->year, this->month, 1), greg_weekday(Friday));
    }

    date scheduler::first_saturday() const
    {
        return next_weekday(date(this->year, this->month, 1), greg_weekday(Saturday));
    }

    date scheduler::first_sunday() const
    {
        return next_weekday(date(this->year, this->month, 1), greg_weekday(Sunday));
    }

    date scheduler::second_monday() const
    {
        return next_weekday(date(this->year, this->month, 8), greg_weekday(Monday));
    }

    date scheduler::second_tuesday() const
    {
        return next_weekday(date(this->year, this->month, 8), greg_weekday(Tuesday));
    }

    date scheduler::second_wednesday() const
    {
        return next_weekday(date(this->year, this->month, 8), greg_weekday(Wednesday));
    }

    date scheduler::second_thursday() const
    {
        return next_weekday(date(this->year, this->month, 8), greg_weekday(Thursday));
    }

    date scheduler::second_friday() const
    {
        return next_weekday(date(this->year, this->month, 8), greg_weekday(Friday));
    }

    date scheduler::second_saturday() const
    {
        return next_weekday(date(this->year, this->month, 8), greg_weekday(Saturday));
    }

    date scheduler::second_sunday() const
    {
        return next_weekday(date(this->year, this->month, 8), greg_weekday(Sunday));
    }

    date scheduler::third_monday() const
    {
        return next_weekday(date(this->year, this->month, 15), greg_weekday(Monday));
    }

    date scheduler::third_tuesday() const
    {
        return next_weekday(date(this->year, this->month, 15), greg_weekday(Tuesday));
    }

    date scheduler::third_wednesday() const
    {
        return next_weekday(date(this->year, this->month, 15), greg_weekday(Wednesday));
    }

    date scheduler::third_thursday() const
    {
        return next_weekday(date(this->year, this->month, 15), greg_weekday(Thursday));
    }

    date scheduler::third_friday() const
    {
        return next_weekday(date(this->year, this->month, 15), greg_weekday(Friday));
    }

    date scheduler::third_saturday() const
    {
        return next_weekday(date(this->year, this->month, 15), greg_weekday(Saturday));
    }

    date scheduler::third_sunday() const
    {
        return next_weekday(date(this->year, this->month, 15), greg_weekday(Sunday));
    }

    date scheduler::fourth_monday() const
    {
        return next_weekday(date(this->year, this->month, 22), greg_weekday(Monday));
    }

    date scheduler::fourth_tuesday() const
    {
        return next_weekday(date(this->year, this->month, 22), greg_weekday(Tuesday));
    }

    date scheduler::fourth_wednesday() const
    {
        return next_weekday(date(this->year, this->month, 22), greg_weekday(Wednesday));
    }

    date scheduler::fourth_thursday() const
    {
        return next_weekday(date(this->year, this->month, 22), greg_weekday(Thursday));
    }

    date scheduler::fourth_friday() const
    {
        return next_weekday(date(this->year, this->month, 22), greg_weekday(Friday));
    }

    date scheduler::fourth_saturday() const
    {
        return next_weekday(date(this->year, this->month, 22), greg_weekday(Saturday));
    }

    date scheduler::fourth_sunday() const
    {
        return next_weekday(date(this->year, this->month, 22), greg_weekday(Sunday));
    }

    date scheduler::fifth_monday() const
    {
        return next_weekday(date(this->year, this->month, 29), greg_weekday(Monday));
    }

    date scheduler::fifth_tuesday() const
    {
        return next_weekday(date(this->year, this->month, 29), greg_weekday(Tuesday));
    }

    date scheduler::fifth_wednesday() const
    {
        return next_weekday(date(this->year, this->month, 29), greg_weekday(Wednesday));
    }

    date scheduler::fifth_thursday() const
    {
        return next_weekday(date(this->year, this->month, 29), greg_weekday(Thursday));
    }

    date scheduler::fifth_friday() const
    {
        return next_weekday(date(this->year, this->month, 29), greg_weekday(Friday));
    }

    date scheduler::fifth_saturday() const
    {
        return next_weekday(date(this->year, this->month, 29), greg_weekday(Saturday));
    }

    date scheduler::fifth_sunday() const
    {
        return next_weekday(date(this->year, this->month, 29), greg_weekday(Sunday));
    }

    date scheduler::last_monday() const
    {
        return next_weekday(date(this->year, this->month, 1).end_of_month() - days(6), greg_weekday(Monday));
    }

    date scheduler::last_tuesday() const
    {
        return next_weekday(date(this->year, this->month, 1).end_of_month() - days(6), greg_weekday(Tuesday));
    }

    date scheduler::last_wednesday() const
    {
        return next_weekday(date(this->year, this->month, 1).end_of_month() - days(6), greg_weekday(Wednesday));
    }

    date scheduler::last_thursday() const
    {
        return next_weekday(date(this->year, this->month, 1).end_of_month() - days(6), greg_weekday(Thursday));
    }

    date scheduler::last_friday() const
    {
        return next_weekday(date(this->year, this->month, 1).end_of_month() - days(6), greg_weekday(Friday));
    }

    date scheduler::last_saturday() const
    {
        return next_weekday(date(this->year, this->month, 1).end_of_month() - days(6), greg_weekday(Saturday));
    }

    date scheduler::last_sunday() const
    {
        return next_weekday(date(this->year, this->month, 1).end_of_month() - days(6), greg_weekday(Sunday));
    }

} // namespace meetup
