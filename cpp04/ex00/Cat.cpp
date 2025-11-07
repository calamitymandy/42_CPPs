#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << Grey << "Cat is created!" << RESET << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
    *this = copy;
    std::cout << "Cat is copied" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
    if (this != &copy)
        type = copy.type;
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << RED << "Cat is destroyed!" << RESET << std::endl;
}

void Cat::makeSound() const {
    std::cout << PURPLE << " 🐱  Meow! Meow!" << RESET << std::endl;
}