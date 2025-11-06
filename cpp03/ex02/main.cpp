#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << std::endl;

    ClapTrap basic("Basic");
    std::cout << std::endl;

    ScavTrap guardian("Guardian");
    std::cout << std::endl;

    FragTrap fraggy("Fraggy");
    std::cout << std::endl;

    fraggy.attack("Whatever target");
    fraggy.takeDamage(99);
    fraggy.beRepaired(10);
    fraggy.highFivesGuys();

//    guardian.guardGate();

    std::cout << std::endl;
    return 0;
}