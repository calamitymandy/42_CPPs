#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        Fixed();
        ~Fixed();
        Fixed(const int intValue);
        Fixed(const float floatValue);
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &assignedCopy);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);

    float   toFloat(void) const;
    int     toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixedNumber);

#endif
