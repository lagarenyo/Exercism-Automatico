
#include "complex_numbers.h"

namespace complex_numbers
{

    Complex::Complex() : real_part(0.0), imaginary_part(0.0) {}

    Complex::Complex(double re, double im) : real_part(re), imaginary_part(im) {}

    double Complex::real() const { return real_part; }

    double Complex::imag() const { return imaginary_part; }

    Complex Complex::operator*(const Complex other_complex) const
    {
        return Complex(((this->real_part * other_complex.real_part) - (this->imaginary_part * other_complex.imaginary_part)),
                       ((this->imaginary_part * other_complex.real_part) + (this->real_part * other_complex.imaginary_part)));
    }

    Complex Complex::operator+(const Complex other_complex) const
    {
        return Complex(this->real_part + other_complex.real_part, this->imaginary_part + other_complex.imaginary_part);
    }

    Complex Complex::operator-(const Complex other_complex) const
    {
        return Complex(this->real_part - other_complex.real_part, this->imaginary_part - other_complex.imaginary_part);
    }

    Complex Complex::operator/(const Complex other_complex) const
    {
        return Complex((((this->real_part * other_complex.real_part) + (this->imaginary_part * other_complex.imaginary_part)) /
                        ((other_complex.real_part * other_complex.real_part) + (other_complex.imaginary_part * other_complex.imaginary_part))),
                       (((this->imaginary_part * other_complex.real_part) - (this->real_part * other_complex.imaginary_part)) /
                        ((other_complex.real_part * other_complex.real_part) + (other_complex.imaginary_part * other_complex.imaginary_part))));
    }

    double Complex::abs() const
    {
        return sqrt((this->real_part * this->real_part) + (this->imaginary_part * this->imaginary_part));
    }

    Complex Complex::conj() const
    {
        return Complex(this->real_part, this->imaginary_part * -1);
    }

    Complex Complex::exp() const
    {
        double ex;

        ex = ::exp(this->real_part);
        return Complex(ex * cos(this->imaginary_part), ex * sin(this->imaginary_part));
    }

} // namespace complex_numbers
