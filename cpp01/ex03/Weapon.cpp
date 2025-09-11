#include "Weapon.hpp"

/* Constructor initializes the attribute _type.
 * setType mutates the attribute: any object holding a reference/pointer to this Weapon will observe the change. */ 

// initializer list: _type is constructed directly with the value of type. type (parameter) is passed in and _type is initialized with it.
Weapon::Weapon(std::string type) : _type(type) {} // Destructor left empty (no dynamic allocation inside Weapon)
Weapon::~Weapon(void) {}

const std::string &Weapon::getType(void) const {
    return this->_type; // ATTRIBUTE accessed via this->_type
}

void Weapon::setType(const std::string &type) {
    this->_type = type; // ATTRIBUTE updated
}