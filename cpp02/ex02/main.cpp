#include <iostream>
#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2)); // Multiplication: 5.05 * 2

    std::cout << "Initial value of a: " << a << std::endl;

    std::cout << "Performing pre-increment on a" << std::endl;
    std::cout << "a after pre-increment (operation: a + 1): " << ++a << std::endl; // Pre-increment

    std::cout << "Value of a after pre-increment: " << a << std::endl;

    std::cout << "Performing post-increment on a." << std::endl;
    std::cout << "Value of a during post-increment (operation: a before incrementing): " << a++ << std::endl; // Post-increment

    std::cout << "Value of a after post-increment: " << a << std::endl;
    std::cout << "Value of b (result of 5.05f * 2): " << b << std::endl; // Result of the multiplication

    std::cout << "Calculating the maximum between a and b." << std::endl;
    std::cout << "The maximum is: " << Fixed::max(a, b) << std::endl; // Comparison

    return 0;
}