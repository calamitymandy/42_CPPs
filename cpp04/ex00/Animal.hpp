#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

// Define colors
#define RESET       "\033[0m"
#define RED         "\033[91m"
#define GREEN       "\033[92m"
#define YELLOW      "\033[93m"
#define ORANGE		"\033[38;5;209m"
#define GRAY		"\033[38;5;225m"
#define CYAN        "\033[96m"
#define PURPLE      "\033[95m"
#define LIGHTBLUE	"\033[38;5;220m"

class Animal {
    protected:
        std::string type;

    public:
        Animal();
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);
        virtual ~Animal();                      // Must be virtual for proper cleanup

        std::string getType() const;
        virtual void makeSound() const;         // Key to polymorphism
};

#endif