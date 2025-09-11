#include "HumanA.hpp"

/* _weapon is a Weapon& reference. It must be initialized in the constructor initializer list.
 * HumanA cannot exist without a valid Weapon (reference enforces this).
*/

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {} // initialize reference in initializer list
HumanA::~HumanA(void) {}

void HumanA::attack(void) const { 
    std::cout << this->_name << " attacks with " << this->_weapon.getType() << std::endl; // Access the weapon type through the reference
}