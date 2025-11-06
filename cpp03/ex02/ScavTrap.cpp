#include "ScavTrap.hpp"

// ---------- Constructors & Destructor ----------

ScavTrap::ScavTrap() {
    std::cout << GREEN << "ScavTrap default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << GREEN << "ScavTrap " << _name << " created" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
    *this = copy;
    std::cout << GREEN << "ScavTrap " << _name << " copied" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
    if (this != &copy) {
        ClapTrap::operator=(copy);
    }
    std::cout << GREEN << "ScavTrap " << _name << " assigned" << RESET << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << RED << "ScavTrap " << _name << " destroyed" << RESET << std::endl;
}

// ---------- Member Functions ----------

void ScavTrap::attack(const std::string &target) {
    if (_energyPoints <= 0 || _hitPoints <= 0) {
        std::cout << GRAY << "ScavTrap " << _name << " 💀  cannot attack" << RESET << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << ORANGE << "ScavTrap " << _name << " ⚔️  slashes " << target
              << ", causing " << _attackDamage << " points of damage!" << GRAY
              << " [HP: " << _hitPoints << " - EP: " << _energyPoints << "]"
              << RESET << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << LIGHTBLUE << "ScavTrap " << _name 
              << " 🛡️  is now in Gate Keeper mode!" 
              << RESET << std::endl;
}