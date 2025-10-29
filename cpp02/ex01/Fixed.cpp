#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy; // calls assignment operator
}

// Copy assignment operator
// Overload of = operator: defines how Fixed objects behave when we use = (assignment operator).
Fixed &Fixed::operator=(const Fixed &assignedCopy) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &assignedCopy) 
        this->_fixedPointValue = assignedCopy.getRawBits();
    return *this;
}

// Int & Float constructors convert the value to a fixed point value

// Int constructor: Converts integer to fixed-point representation
Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    // Shift left by _fractionalBits to encode integer as fixed-point (x 256)
    this->_fixedPointValue = intValue << this->_fractionalBits;
}

// Float constructor: Converts float to fixed-point representation
// Multiply by 2^_fractionalBits and round
Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(floatValue * (1 << this->_fractionalBits));
    // We use multiplication instead of bit shifting because you can’t bit-shift floats,
    // bit-shifts only work on integers.
    // round to nearest integer roundf(42.42 * Compute multiplier 1 << 8 = 256)
    // so: roundf(10859.52) = 10860 and we store: _fixedPointValue = 10860
}

// Returns the raw stored fixed-point value
int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

// Sets the raw fixed-point value directly
void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// toFloat & toInt doing the opposite operation that we've done before

// Converts fixed-point value to float
float Fixed::toFloat(void) const {
    // Divide by 2^_fractionalBits to get real value
    return static_cast<float>(this->_fixedPointValue) / (1 << this->_fractionalBits);
}

// Converts fixed-point value to int
int Fixed::toInt(void) const {
    // Shift right to remove fractional part
    return this->_fixedPointValue >> this->_fractionalBits;
}

/* Overload of insertion operator: defines how Fixed objects behave when we use std::cout <<.
   Normally, std::cout knows how to print basic types (like int, float, std::string) 
   but not your custom class Fixed. So you "teach" it what to do. That’s what operator overload does
   In this function we overload operator to print the fixed number as a floating-point value.
*/
std::ostream &operator<<(std::ostream &out, const Fixed &fixedNumber) {
    out << fixedNumber.toFloat();
    return out;
}
