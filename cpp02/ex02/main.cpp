#include <iostream>
#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2)); // Multiplication: 5.05 * 2
    Fixed const c(Fixed(10) / Fixed(2));
    Fixed const d(Fixed(10) - Fixed(2));
    Fixed const e(Fixed(10.5f) + Fixed(2));
    Fixed const f(Fixed(10) != Fixed(9));

    std::cout << "Initial value of a: " << a << std::endl;
    std::cout << std::endl;

    std::cout << "---Performing pre-increment on a---" << std::endl;
    std::cout << "a after pre-increment (operation: ++a): " << ++a << std::endl; // Pre-increment
    std::cout << "Value of a after pre-increment: " << a << std::endl;
    std::cout << std::endl;

    std::cout << "---Performing post-increment on a---" << std::endl;
    std::cout << "Value of a during post-increment (operation: a++): " << a++ << std::endl; // Post-increment
    std::cout << "Value of a after post-increment: " << a << std::endl;
    std::cout << std::endl;

    std::cout << "Value of b (result of 5.05f * 2): " << b << std::endl; // Result of the multiplication
    std::cout << std::endl;
    
    std::cout << "---Calculating the maximum between a and b---" << std::endl;
    std::cout << "The maximum is: " << Fixed::max(a, b) << std::endl; // Comparison

    std::cout << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Value of c (result of 10 / 2): " << c << std::endl; // Result of the multiplication
    std::cout << std::endl;
    std::cout << "Value of d (result of 10 - 2): " << d << std::endl; // Result of the multiplication
    std::cout << std::endl;
    std::cout << "Value of e (result of 10,5 + 2): " << e << std::endl; // Result of the multiplication
    std::cout << std::endl;
    std::cout << "Value of f (result of 10 != 9): " << f << std::endl; // Result of the multiplication
    std::cout << std::endl;
    return 0;
}