#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
 * Example from the subject — demonstrates that changing the Weapon's type
 * is reflected in both HumanA (reference) and HumanB (pointer).
 */
int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    {
        HumanB peter("Lucy");
        peter.attack();
    }
    return 0;
}