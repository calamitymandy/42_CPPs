#include "HumanB.hpp"

/*
 * _weapon initialized to 0 (null pointer) because this class allows no weapon initially.
 * setWeapon takes Weapon& to avoid passing 0 and stores its address.
 * attack() checks pointer before dereferencing.
 */

    HumanB::HumanB(std::string name) : _name(name), _weapon(0) {} // use 0 for C++98 null
    HumanB::~HumanB(void) {}

    void HumanB::setWeapon(Weapon &weapon) {
        this->_weapon = &weapon; // store address of passed weapon
    }

    void HumanB::attack(void) const {
        if (this->_weapon) {
            std::cout << this->_name << " attacks with " << this->_weapon->getType() << std::endl; 
        } else {
            std::cout << this->_name << " attacks with bare hands!!" << std::endl; 
        }
    }