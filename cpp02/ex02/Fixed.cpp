#include "Fixed.hpp"

// ----------------------------- Constructors & Destructor -----------------------------
Fixed::Fixed() : _fixedPointValue(0) {
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    //std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
    //std::cout << "Copy constructor called" << std::endl;
    *this = copy; // calls assignment operator
}

Fixed::Fixed(const int intValue) {
    //std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = intValue << this->_fractionalBits;
}

Fixed::Fixed(const float floatValue) {
    //std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(floatValue * (1 << this->_fractionalBits));
}

// ----------------------------- Assignment -----------------------------
Fixed &Fixed::operator=(const Fixed &assignedCopy) {
    std::cout << "Copy assignment operator called" << std::endl;
    if( this != &assignedCopy) 
        this->_fixedPointValue = assignedCopy.getRawBits();
    return *this;
}

// ----------------------------- Arithmetic Operators -----------------------------
Fixed Fixed::operator+(const Fixed &value) const {
    return Fixed(this->toFloat() + value.toFloat());
    // a is a Fixed object, so C++ calls: a.operator+(b); 
    // `this` points to `a` and `value` is a const Fixed& reference to `b`
}

Fixed Fixed::operator-(const Fixed &value) const {
    return Fixed(this->toFloat() - value.toFloat());
}

Fixed Fixed::operator*(const Fixed &value) const {
    return Fixed(this->toFloat() * value.toFloat());
}

Fixed Fixed::operator/(const Fixed &value) const {
    return Fixed(this->toFloat() / value.toFloat());
}

// ----------------------------- Increment / Decrement -----------------------------
Fixed &Fixed::operator++(void) {    // ++a
    this->_fixedPointValue++;       // increment value
    return *this;                   // return new value (by reference)
}

Fixed Fixed::operator++(int) {      // a++:
    Fixed temp(*this);              // save the current value (before increment)
    this->_fixedPointValue++;       // increase the value
    return temp;                    // return the old value (by copy)
}

Fixed &Fixed::operator--(void) {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;
}

// ----------------------------- Comparison Operators -----------------------------
bool Fixed::operator>(const Fixed &value) const {
    return this->toFloat() > value.toFloat();       // Return `true` if the result of the operation is `true`
}

bool Fixed::operator<(const Fixed &value) const {
    return this->toFloat() < value.toFloat();
}

bool Fixed::operator>=(const Fixed &value) const {
    return this->toFloat() >= value.toFloat();
}

bool Fixed::operator<=(const Fixed &value) const {
    return this->toFloat() <= value.toFloat();
}

bool Fixed::operator==(const Fixed &value) const {
    return this->toFloat() == value.toFloat();
}

bool Fixed::operator!=(const Fixed &value) const {
    return this->toFloat() != value.toFloat();
}

// ----------------------------- Min / Max -----------------------------
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b ? a : b);                 // ternary operator: If a < b, it returns a; otherwise, it returns b.
}

/* if you pass in const Fixed objects (like in Fixed const b(10);), 
C++ must call the const version, otherwise, it would try to return 
a reference to something you’re not allowed to modify, which isn’t 
allowed.
*/
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { 
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b ? a : b);
}

// ----------------------------- Conversions -----------------------------
int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_fixedPointValue) / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> this->_fractionalBits;
}

// ----------------------------- Stream output -----------------------------
std::ostream &operator<<(std::ostream &out, const Fixed &fixedNumber) {
    out << fixedNumber.toFloat();
    return out;
}
