#include "Fixed.hpp"

// Default constructor -> initializes _fixedPointValue to 0.
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Copy constructor -> uses the assignment operator (*this = other) to copy.
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/* Copy assignment operator:
    - Needed for proper OCF.
    - Avoids copying onto itself.
    - Uses getRawBits() for consistency.*/
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits(); // Deep copy raw value
    }
    return *this;
}

// Getter -> returns the raw integer value.
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

// Setter -> allows manual setting.
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}