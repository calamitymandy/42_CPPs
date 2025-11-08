#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    protected:
        std::string type;
    
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal &operator=(const WrongAnimal &copy);
        ~WrongAnimal();                                     // not virtual on purpose

        std::string getType() const;
        void makeSound() const;                             // not virtual either
};

#endif

