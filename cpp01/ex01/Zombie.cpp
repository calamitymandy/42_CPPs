#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::~Zombie(void) {
    std::cout << this->thename << " is very dead... RIP." << std::endl;
}

void Zombie::setName(std::string name) {
    this->thename = name;
}

void Zombie::announce(void) {
    std::cout << this->thename << ": BraiiiiiiinnnzzzZ..." << std::endl;
}