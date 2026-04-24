/* Key Concepts:
These are function templates, so:
    - They must be defined in a header file (.hpp) NOT in a .cpp
    - They must work with:
        int, std::string, etc.
        Any type that supports:
            assignment (=)
            comparison (<, >, ==)
*/

#include <iostream>
#include "whatever.hpp"
#include <string>

int main(void) {

    std::cout << "________ SUBJECT TEST ____________" << std::endl;
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    
    std::cout << "___________ MORE TESTS ___________" << std::endl;
    std::cout << " - Char: " << std::endl;
    
    char char1 = 'a';
    char char2 = 'b';
    
    ::swap(char1, char2);
    std::cout << "char1 = " << char1 << ", char2 = " << char2 << std::endl;
    std::cout << "min(char1, char2) = " << ::min( char1, char2 ) << std::endl;
    std::cout << "max(char1, char2) = " << ::max( char1, char2 ) << std::endl;
    std::cout << std::endl;
    std::cout << " - Double: " << std::endl;
    
    double d1 = 4.444;
    double d2 = -5.555;
    
    ::swap( d1, d2 );
    std::cout << "d1 = " << d1 << ", d2 = " << d2 << std::endl;
    std::cout << "min(d1, d2) = " << ::min( d1, d2 ) << std::endl;
    std::cout << "max(d1, d2) = " << ::max( d1, d2 ) << std::endl;
    
    return 0;
}

/*
int main(void)
{
	Awesome a(2), b(4);

        swap(a, b);
        std::cout << a << " " << b << std::endl;
        std::cout << max(a, b) << std::endl;
        std::cout << min(a, b) << std::endl;
        return (0);
}
*/