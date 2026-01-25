#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

namespace space_age
{
    class space_age
    {
        long int value;

    private:
        double tierra = 31557600.00; 
        double mercurio = this->tierra * 0.2408467;
        double venus = this->tierra * 0.61519726;
        double marte = this->tierra * 1.8808158;
        double jupiter = this->tierra * 11.862615;
        double saturno = this->tierra * 29.447498;
        double urano = this->tierra * 84.016846;
        double neptuno = this->tierra * 164.79132;

    public:
        space_age(long int num);
        long int seconds() const;
        double on_earth() const;
        double on_mercury() const;
        double on_venus() const;
        double on_mars() const;
        double on_jupiter() const;
        double on_saturn() const;
        double on_uranus() const;
        double on_neptune() const;
    };
}
#endif