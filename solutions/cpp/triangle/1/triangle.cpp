#include "triangle.h"

namespace triangle
{
    flavor kind(double a, double b, double c)
    {
        if ((a > 0) && (b > 0) && (c > 0) && ((a + b) >= c) && ((a + c) >= b) && ((b + c) >= a))
        {
            if ((a == b) && (b == c))
                return flavor::equilateral;
            else if ((a == b) || (a == c) || (b == c))
                return flavor::isosceles;
            else if ((a != b) && (a != c) && (b != c))
                return flavor::scalene;
        }
        throw domain_error("Otro tipo");
    }
}
