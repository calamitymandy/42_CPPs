#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    brain = new Brain;
    std::cout << ORANGE << "Cat is created!" << RESET << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
    std::cout << "Cat is copied" << std::endl;
    brain = new Brain(*copy.brain);				// it constructs a new Brain, not just copies the pointer, that makes the copy deep.
}

Cat &Cat::operator=(const Cat &copy) {
    if (this != &copy) {
        Animal::operator=(copy);
        delete brain;
        brain = new Brain(*copy.brain);			// Deep copy new Brain
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << RED << "Cat is destroyed!" << RESET << std::endl;
}

void Cat::makeSound() const {
    std::cout << PURPLE << " 🐱  Meow! Meow!" << RESET << std::endl;
}

std::string const &Cat::getIdea(int index) const {
    return brain->getIdea(index);
}

void Cat::setIdea(int index, std::string const &idea) {
    brain->setIdea(index, idea);
}