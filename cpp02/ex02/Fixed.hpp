#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

/*
The overload of operators allows to define how the operators must act with custom classes.
In this case we overload + - * / ++ -- > < >= <= == != << >>
In ex01 we already overloaded = <<.
*/

class Fixed {

    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        // Constructors & Destructor
        Fixed();
        ~Fixed();
        Fixed(const int intValue);
        Fixed(const float floatValue);
        Fixed(const Fixed &copy);

        // Assignment (=) operator
        Fixed &operator=(const Fixed &assignedCopy);

        // Arithmetic operators
        Fixed operator+(const Fixed &value) const;
        Fixed operator-(const Fixed &value) const;
        Fixed operator*(const Fixed &value) const;
        Fixed operator/(const Fixed &value) const;

        // Comparison operators
        bool operator>(const Fixed &value) const;
        bool operator<(const Fixed &value) const;
        bool operator>=(const Fixed &value) const;
        bool operator<=(const Fixed &value) const;
        bool operator==(const Fixed &value) const;
        bool operator!=(const Fixed &value) const;

        // Increment / Decrement operators
        Fixed &operator++();            // pre-increment (++a)
        Fixed operator++(int);          // post-increment (a++)
        Fixed &operator--();            // pre-increment (--a)
        Fixed operator--(int);          // post-increment (a--)

        // Static min/max
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        
        // Conversion and accessors
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixedNumber);

#endif
