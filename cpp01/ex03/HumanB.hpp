#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

/*
 * HumanB: may or may not have a Weapon.
 * We store a pointer to Weapon so it can be null (no weapon),
 * and it can be set later.
 */

class HumanB {
    private:
        std::string _name;
        Weapon *_weapon; // ATTRIBUTE: pointer to Weapon (may be 0 if none)

    public:
        HumanB(std::string name);
        ~HumanB(void);

    void setWeapon(Weapon &weapon);   // assign a weapon (stores pointer to it)
    void attack(void) const;        // prints attack or "has no weapon"
};

#endif