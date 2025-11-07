#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

// Define colors
#define RESET       "\033[0m"
#define RED         "\033[91m"
#define GREEN       "\033[92m"
#define YELLOW      "\033[93m"
#define ORANGE		"\033[38;5;209m"
#define GRAY		"\033[38;5;225m"
#define CYAN        "\033[96m"
#define PURPLE      "\033[95m"
#define LIGHTBLUE	"\033[38;5;220m"

class ClapTrap {
    protected:								//In C++, a derived class (like ScavTrap) cannot access private members of its base class directly. But it can access members declared as protected.
        std::string		_name;
        unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

    public:
		ClapTrap();										// Default constructor
		ClapTrap(std::string name);						// Constructor with name
		ClapTrap(ClapTrap const &copy);					// Copy constructor
		ClapTrap &operator=(ClapTrap const &copy);		// Copy assignment
		~ClapTrap();									// Destructor

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif