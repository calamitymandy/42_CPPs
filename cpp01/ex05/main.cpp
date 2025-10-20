#include "Harl.hpp"

int main() {
    Harl harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    // Example of invalid input
    harl.complain("THEINVALIDINPUT");

    return 0;
}