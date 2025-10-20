#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "-------Correct input-------" << std::endl;
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    std::cout << std::endl;

    // Example of invalid input
    std::cout << "-------Example of invalid input-------" << std::endl;
    harl.complain("THEINVALIDINPUT");

    return 0;
}