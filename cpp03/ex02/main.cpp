#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << std::endl;

    std::cout << "-------only ClapTrap-------" << std::endl;
    ClapTrap basic("Basic");
    std::cout << std::endl;

    std::cout << "-------ScavTrap-------" << std::endl;
    ScavTrap guardian("Guardian");
    std::cout << std::endl;

    std::cout << "-------FragTrap-------" << std::endl;
    FragTrap fraggy("Fraggy");
    std::cout << std::endl;

    fraggy.attack("Whatever target");
    fraggy.takeDamage(99);
    fraggy.beRepaired(10);
    fraggy.highFivesGuys();

//    guardian.guardGate();
//    fraggy.guardGate(); // gives an error FragTap only inherits from ClapTrap and no ScavTrap

    std::cout << std::endl;
    return 0;
}