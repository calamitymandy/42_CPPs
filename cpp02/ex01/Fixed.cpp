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
    *this = copy;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &assignedCopy) {
    std::cout << "Copy assignment operator called" << std::endl;
    if( this != &assignedCopy) 
        this->_fixedPointValue = assignedCopy.getRawBits();
    return *this;
}

// Int constructor
// Converts integer to fixed-point representation
Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    // Shift left by _fractionalBits to encode integer as fixed-point
    this->_fixedPointValue = intValue << this->_fractionalBits;
}

// Float constructor
// Converts float to fixed-point representation
Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    // Multiply by 2^_fractionalBits and round
    this->_fixedPointValue = roundf(floatValue * (1 << this->_fractionalBits));
}

// Returns the raw stored fixed-point value
int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

// Sets the raw fixed-point value directly
void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

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

// Overload of insertion operator
// Prints the number as a floating-point value
std::ostream &operator<<(std::ostream &out, const Fixed &fixedNumber) {
    out << fixedNumber.toFloat();
    return out;
}
