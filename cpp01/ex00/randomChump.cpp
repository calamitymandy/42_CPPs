#include "Zombie.hpp"

void    randomChump(std::string name) {
    Zombie zombie(name); // Local variable (stack allocation)
    zombie.announce();   // Announces itself immediately
}