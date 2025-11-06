#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();                                     // Default constructor
        ScavTrap(std::string name);                     // Name constructor
        ScavTrap(const ScavTrap &copy);                 // Copy constructor
        ScavTrap &operator=(const ScavTrap &copy);      // Copy assignment
        ~ScavTrap();                                    // Destructor

		void attack(const std::string &target);         // Override attack
        void guardGate();                               // New ability
};

#endif