#include "Animal.hpp"

Animal::Animal() {
    type = "Animal";
    std::cout << GREEN << "Animal is created!" << RESET << std::endl;
}

Animal::Animal(const Animal &copy) {
    *this = copy;
    std::cout << "Animal is copied" << std::endl;
}

Animal &Animal::operator=(const Animal &copy) {
    if (this != &copy)
        type = copy.type;
    std::cout << "Animal assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << RED << "Animal is destroyed!" << RESET << std::endl;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << GRAY << ITALIC << "The animal makes a sound, but from which animal is it?" << RESET << std::endl;
}