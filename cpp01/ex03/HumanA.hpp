#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

/*
 * HumanA: always has a Weapon.
 * We store a reference to Weapon because HumanA is guaranteed to be armed.
 */

class HumanA {
    private:
        std::string _name; // ATTRIBUTE: human's name
        Weapon &_weapon; // ATTRIBUTE: reference to a Weapon (cannot be null)

    public:
        HumanA(std::string name, Weapon &weapon); // must provide a Weapon at construction
        ~HumanA(void);

        void attack(void) const; // prints: "<name> attacks with their <weapon type>"
};

#endif