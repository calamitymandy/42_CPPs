#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/* Why use a pointer vs a reference for Weapon?
 *  Reference (Weapon&) — used in HumanA:
        - Must be initialized at construction and cannot be changed to refer to another object later.
        - It cannot be null. That enforces at the type level: HumanA is always armed.
        - Use a reference when the object must have a valid Weapon for its whole life and you want 
        the syntax to look like direct member access (_weapon.getType()).
 *  Pointer (Weapon*) — used in HumanB:
        - Can be initialized to 0 (null) and later set to point to an actual Weapon.
        - Can be reseated (you can change which Weapon it points to).
        - Use a pointer when the association is optional or needs to be changed after construction 
        (HumanB may start unarmed and be armed later).

 * Both pointer and reference here are non-owning: they do not manage the Weapon memory; they refer 
 * to an external Weapon that is managed elsewhere (stack in our example). 
*/

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
    // no weapon -> default message: "with bare hands!!"
    {
        HumanB lucy("Lucy");
        lucy.attack();
    }
    return 0;
}

