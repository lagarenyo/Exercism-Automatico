#include "space_age.h"

space_age::space_age::space_age(long int num)
{
    this->value = num;
}
long int space_age::space_age::seconds() const
{
    return this->value;
}

double space_age::space_age::on_earth() const
{
    return (this->value / this->tierra);
}
double space_age::space_age::on_mercury() const
{
    return (this->value / this->mercurio);
}
double space_age::space_age::on_venus() const
{
    return (this->value / this->venus);
}
double space_age::space_age::on_mars() const
{
    return (this->value / this->marte);
}
double space_age::space_age::on_jupiter() const
{
    return (this->value / this->jupiter);
}
double space_age::space_age::on_saturn() const
{
    return (this->value / this->saturno);
}
double space_age::space_age::on_uranus() const
{
    return (this->value / this->urano);
}
double space_age::space_age::on_neptune() const
{
    return (this->value / this->neptuno);
}