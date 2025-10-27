#include "ClapTrap.hpp"

int main (void) {
    ClapTrap Player1 = ClapTrap("Player 1");
    ClapTrap Player2 = ClapTrap("Player 2");

    Player1.attack("Ennemy 1");
    Player1.takeDamage(5);
    Player1.beRepaired(3);

    Player1.attack("Ennemy 2");
    Player1.takeDamage(20);
    Player1.beRepaired(10);

    Player2.attack("Ennemy 3");
    Player2.takeDamage(20);
    Player2.beRepaired(10);

    Player2.attack("Ennemy 4");
    Player2.takeDamage(5);
    Player2.beRepaired(3);

    return 0;
}