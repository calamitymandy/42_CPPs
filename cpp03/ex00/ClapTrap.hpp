#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    private:
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

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif