#include "ClapTrap.hpp"

/* Inheritance is one of the key concepts of object-oriented programming (OOP).
 * It allows you to create a new class (a child or derived class) that inherits 
 * attributes and behaviors from another class (the parent or base class).
 
 - The base class defines common properties and functions that other classes can reuse.
 - The derived class can reuse, extend, or override the behavior of the base class.
*/

// ---------- Constructors & Destructor ----------

	ClapTrap::ClapTrap() : _name("No name"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
        std::cout << "Claptrap - default " << _name << " created" << std::endl;
    }

	ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
        std::cout << GREEN << "Claptrap " << _name << " created" << RESET << std::endl;
    }

	ClapTrap::ClapTrap(ClapTrap const &copy) {
        *this = copy;
        std::cout << "Claptrap " << _name << " copied" << std::endl;
    }

	ClapTrap &ClapTrap::operator=(ClapTrap const &copy) {
        if (this != &copy) {
            _name = copy._name;
            _hitPoints = copy._hitPoints;
            _energyPoints = copy._energyPoints;
            _attackDamage = copy._attackDamage;
        }
        std::cout << "Claptrap " << _name << " assigned" << std::endl;
        return *this;
    }

	ClapTrap::~ClapTrap() {
        std::cout << RED << "Claptrap " << _name << " destroyed" << RESET << std::endl;
    }

    // ---------- Member Functions ----------

    void ClapTrap::attack(const std::string& target) {
        if (_energyPoints <= 0 || _hitPoints <= 0) {
            std::cout << GRAY << "Claptrap " << _name << " 💀  has no energy or hit points left to attack" << RESET << std::endl;
            return;
        }
        _energyPoints--;
        std::cout << YELLOW << "Claptrap " << _name << " 💥  attacks " << target << " causing " << _attackDamage << " points of damage!" << GRAY << "[HP: " << _hitPoints << " - EP: " << _energyPoints << "]" << RESET << std::endl;
    }

    void ClapTrap::takeDamage(unsigned int amount) {
        if (amount >= _hitPoints || _hitPoints <= 0)
            _hitPoints = 0;
        else
            _hitPoints -= amount;
        std::cout << PURPLE << "Claptrap " << _name << " 💔  takes " << amount << " points of damage!" << GRAY << "[HP: " << _hitPoints << " - EP: " << _energyPoints << "]" << RESET << std::endl;
        if (_hitPoints <= 0) {
            _hitPoints = 0;
            std::cout << GRAY << "Claptrap " << _name << " 💀  has died: no hit points left" << RESET << std::endl;
        }
    }

    void ClapTrap::beRepaired(unsigned int amount) {
        if (_energyPoints <= 0) {
            std::cout << GRAY << "Claptrap " << _name << " 💀  has no energy left to repair itself" << RESET << std::endl;
            return;
        }
        if (_hitPoints <= 0) {
            std::cout << GRAY << "Claptrap " << _name << " 💀  is done and beyond repair" << RESET << std::endl;
            return;
        }
        _hitPoints += amount;
        _energyPoints--;
        std::cout << CYAN << "Claptrap " << _name << " 🩹  repairs itself for " << amount << " hit points!" << GRAY << "[HP: " << _hitPoints << " - EP: " << _energyPoints << "]" << RESET << std::endl;
    }