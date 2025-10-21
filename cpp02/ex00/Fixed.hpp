#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int _fixedPointValue;                   // Raw integer value of the fixed-point number
        static const int _fractionalBits = 8;   // Number of fractional bits (always 8)
    
    public:
        Fixed();                                // Default constructor
        ~Fixed();                               // Destructor
        Fixed(const Fixed &other);              // Copy constructor
        Fixed &operator=(const Fixed &other);   // Copy assignment operator

        int getRawBits(void) const;             // Returns the raw integer value
        void setRawBits(int const raw);         // Sets the raw integer value
};

#endif
