#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";   // Create a string variable
    std::string *stringPTR = &str;          // Create a pointer to the string
    std::string &stringREF = str;           // Create a reference to the string
    
    // --- Print memory addresses ---
    std::cout << "Memory address of string variable: " << &str << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << std::endl;

    // --- Print values ---
    std::cout << "Value of string variable: " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: "<< stringREF << std::endl;

    return 0;
}