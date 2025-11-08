#include "ScavTrap.hpp"

int main() {

    ScavTrap selena = ScavTrap("Selena");
    std::cout << std::endl;

    selena.attack("Pirate");
    selena.takeDamage(30);
    selena.beRepaired(20);
    selena.guardGate();
    std::cout << std::endl;

    ScavTrap guardian = ScavTrap("Guardian");
    std::cout << std::endl;

    guardian.attack("wanderer");
    guardian.guardGate();
    std::cout << std::endl;
    
    //--------- ClapTrap example-------------
    ClapTrap oldman = ClapTrap("Ol'man");
    oldman.attack("in the air");
    std::cout << std::endl;

    return 0;
}