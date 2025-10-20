#include "Zombie.hpp"

Zombie* newZombie(std::string name) { // PARAMETER "name"
    return new Zombie(name);          // PARAMETER passed to constructor
}