#include "Fixed.hpp"

int main(void) {
    Fixed a;                    // Default constructor
    Fixed const b(10);          // Copy constructor (int)
    Fixed const c(42.42f);      // Copy constructor (float)
    Fixed const d(b);           // Copy assignment operator (int)

    a = Fixed(1234.4321f);      // Compound operation that involves 
    // temporary object creation, assignment, then temporary destruction:
    // Float constructor called → Copy assignment operator called → Destructor called
    // temporaries are created for right-hand expressions and are 
    // destroyed after the full-expression (after the assignment completes).

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
