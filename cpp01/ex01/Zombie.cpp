#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::~Zombie(void) {
    std::cout << this->thename << " nº"<< this->theid << " is very dead... RIP 💀" << std::endl;
}

void Zombie::setName(std::string name, int id) {
    this->thename = name;
    this->theid = id;
}

void Zombie::announce(void) {
    std::cout << this->thename << ": BraiiiiiiinnnzzzZ..." << std::endl;
}