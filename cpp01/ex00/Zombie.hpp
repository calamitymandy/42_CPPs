#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    private:
        std::string name; // ATTRIBUTE: belongs to each Zombie object

    public:
        Zombie(std::string name); // Constructor: called when a Zombie is created // PARAMETER "name" here is only passed to the constructor
        ~Zombie();                // Destructor: called automatically when a Zombie is destroyed
        void announce(void);      // Public member function: makes the zombie announce itself
};

Zombie* newZombie(std::string name); // Function that creates a Zombie on the heap and returns its pointer
void    randomChump(std::string name); // Function that creates a Zombie on the stack and makes it announce itself immediately

#endif