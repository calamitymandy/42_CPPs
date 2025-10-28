#include "ScavTrap.hpp"

int main() {


    ScavTrap Player1 = ScavTrap("Selena");
    std::cout << std::endl;

    Player1.attack("Pirate");
    Player1.takeDamage(30);
    Player1.beRepaired(20);
    Player1.guardGate();
    std::cout << std::endl;

    ScavTrap Player2 = ScavTrap("Guardian");
    std::cout << std::endl;

    Player2.attack("wanderer");
    Player2.guardGate();
    std::cout << std::endl;
    
    ClapTrap Player3 = ClapTrap("Ol'man");
    Player3.attack("in the air");
    std::cout << std::endl;

    return 0;
}