#include "FragTrap.hpp"

// ---------- Constructors & Destructor ----------

FragTrap::FragTrap() {
    _name = "No name";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << GREEN << "FragTrap " << _name << " ⚙️  created... by default" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << GREEN << "FragTrap " << _name << " ⚙️  created... it's alive!" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
    *this = copy;
    std::cout << GREEN << "FragTrap " << _name << " copied" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
    if (this != &copy)
        ClapTrap::operator=(copy);
    std::cout << GREEN << "FragTrap " << _name << " assigned" << RESET << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << RED << "FragTrap " << _name << " 💥  exploded and is no more..." << RESET << std::endl;
}

// ---------- Member Functions ----------

void FragTrap::attack(const std::string &target) {
    if (_energyPoints <= 0 || _hitPoints <= 0) {
        std::cout << GRAY << "FragTrap " << _name << " 🪫  cannot attack" << RESET << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << RED << "FragTrap " << _name << " 🤜  punch in the face " << target
              << ", causing " << _attackDamage << " points of damage!" << GRAY
              << " [HP: " << _hitPoints << " - EP: " << _energyPoints << "]"
              << RESET << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout   << GREEN << "FragTrap " << _name
                << " ✋  requests a BIG high five!  ✋"
                << RESET << std::endl;
}