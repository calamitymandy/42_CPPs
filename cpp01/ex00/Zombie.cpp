#include "Zombie.hpp"

/* this->name means "the name attribute of the current object."
 *
 * Constructor → assigns the zombie’s name.
 * Destructor → prints a message when the zombie is deleted (help tracking heap allocations).
 * announce() → prints the “braiiiiinzz” message in the required format.
*/

Zombie::Zombie(std::string name) { // PARAMETER: "name"
    this->name = name; // OR Zombie::name = name; to store the name passed to the constructor
    // Left side = ATTRIBUTE, Right side = PARAMETER
}

Zombie::~Zombie() {
    std::cout << this->name << " is destroyed." << std::endl;
    //this->name = "💀 (invalid)"; // put this to "show" that stackZombie is destroyed
}

void    Zombie::announce(void) {
        std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}