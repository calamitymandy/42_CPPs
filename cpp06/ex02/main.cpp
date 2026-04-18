#include "Functions.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>

/* We need to identify the real type of an object at runtime (WITHOUT using typeid)
So we use: dynamic_cast
*/

int main() {
    Base *base = generate();

    std::cout << "--------------------------" << std::endl;

    std::cout << "Identify using pointer: " << std::endl;
    identify(base);

    std::cout << "--------------------------" << std::endl;

    std::cout << "Identify using reference: " << std::endl;
    identify(*base);

    std::cout << "------------ERROR CASES--------------" << std::endl;

    // trigger the generate error case by changing: int random = rand() % 5;
    
    // Error case for pointer
    identify(NULL);

    //error case for reference
    class D : public Base {};
    Base* errorD = new D();
    identify(*errorD);
    delete errorD;

    delete base;
    return 0;
}