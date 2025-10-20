#include "Harl.hpp"

// constructor
Harl::Harl() {}

// Destructor
Harl::~Harl() {}

void Harl::debug(void) {
    std::cout << "DEBUG: I love having extra bacon for my "
              << "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
              << std::endl;
}

void Harl::info(void) {
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. "
              << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
              << std::endl;
}

void Harl::warning(void) {
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. "
              << "I’ve been coming for years, whereas you started working here just last month."
              << std::endl;
}

void Harl::error(void) {
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now."
              << std::endl;
}

void Harl::complain(std::string level) {
    // Array of pointers to member functions
    void (Harl::*functions[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    // Array of corresponding level strings
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    // Iterate to find a match
    // If the level matches a string, the corresponding function is called 
    // dynamically with (this->*functions[i])();.
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*functions[i])(); // Call the corresponding member function
            return;
        }
    }
    std::cout << "Unknown level: " << level << std::endl;
}