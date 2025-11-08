#include "ClapTrap.hpp"

int main() {
    ClapTrap Player1 = ClapTrap("Player 1");
    ClapTrap Player2 = ClapTrap("Player 2");

    std::cout << std::endl;
    Player1.attack("Lisa");
    Player1.takeDamage(5);
    Player1.beRepaired(3);
    
    std::cout << std::endl;
    Player2.takeDamage(9);
    Player2.beRepaired(1);
    Player2.attack("Bob");
    Player2.attack("Bob");
    Player2.attack("Bob");
    Player2.attack("Bob");
    //Player2.takeDamage(2);
    Player2.attack("Bob");
    Player2.attack("Bob");
    Player2.attack("Bob");
    Player2.attack("Bob");
    //Player2.attack("Bob");
    Player2.beRepaired(1);
    //Player2.attack("Bob");
    
    std::cout << std::endl;

    return 0;
}