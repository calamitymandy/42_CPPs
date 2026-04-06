#include "Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

// -------- generate --------
Base    *generate(void) {
    srand(time(0));
    int random = rand() % 3;

    switch (random) {
        case 0:
            std::cout << "Generated A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated C" << std::endl;
            return new C();
        default:
            std::cout << "Error generating!" << std::endl;
            return NULL;
    }
}

/*  Cast type       Failure behavior

    pointer         returns NULL
    reference	    throws exception
*/

// -------- identify pointer --------
// Use dynamic_cast with pointers
// If cast fails → returns NULL
// If cast works → returns valid pointer

void    identify(Base *pointer) {
    if (dynamic_cast<A *>(pointer))
        std::cout << "Identified A" << std::endl;
    else if (dynamic_cast<B *>(pointer))
        std::cout << "Identified B" << std::endl;
    else if (dynamic_cast<C *>(pointer))
        std::cout << "Identified C" << std::endl;
    else
        std::cout << "Error identifying class type for pointer!" << std::endl;
}

// -------- identify reference --------
// NO POINTERS allowed
// Must use reference casting
void    identify(Base &pointer) {
    try {
        (void)dynamic_cast<A &>(pointer);
        std::cout << "Identified A" << std::endl;
        return;
    }
    catch (...) {}

    try {
        (void)dynamic_cast<B &>(pointer);
        std::cout << "Identified B" << std::endl;
        return;
    }
    catch (...) {}

    try {
        (void)dynamic_cast<C &>(pointer);
        std::cout << "Identified C" << std::endl;
        return;
    }
    catch (...) {}
    std::cout << "Error identifying class type for reference!\n";
}