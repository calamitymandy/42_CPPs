#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    private:
        std::string thename; // Attribute that stores the zombie's name

    public:
        Zombie();                   // Default constructor (needed for horde)
        ~Zombie();                  // Destructor (debug message)
        void setName(std::string);  // Assign a name to the zombie
        void announce(void);        // Zombie announces itself
};

Zombie* zombieHorde(int N, std::string name); 

#endif