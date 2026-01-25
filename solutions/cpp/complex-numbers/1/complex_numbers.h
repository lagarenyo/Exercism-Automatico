#include <math.h>

#ifndef M_E
#define M_E 2.71828182845904523536
#endif

#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H

namespace complex_numbers
{
#define local_M_E 2.71828182845904523536

    class Complex
    {
    public:
        Complex();
        Complex(double re, double im);
        double real() const;
        double imag() const;
        Complex operator*(const Complex other_complex) const;
        Complex operator+(const Complex other_complex) const;
        Complex operator-(const Complex other_complex) const;
        Complex operator/(const Complex other_complex) const;
        double abs() const;
        Complex conj() const;
        Complex exp() const;

    private:
        double real_part;
        double imaginary_part;
    };

} // namespace complex_numbers

#endif // COMPLEX_NUMBERS_H
