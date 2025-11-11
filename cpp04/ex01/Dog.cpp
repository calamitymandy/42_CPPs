#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	brain = new Brain;
	std::cout << CYAN << "Dog is created!" << RESET << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	std::cout << "Dog is copied" << std::endl;
	brain = new Brain(*copy.brain);					// it constructs a new Brain, not just copies the pointer, that makes the copy deep.
}

Dog &Dog::operator=(const Dog &copy) {
	if (this != &copy) {
		Animal::operator=(copy);
		delete brain;								// Avoid memory leak — delete old brain
		brain = new Brain(*copy.brain);				// Deep copy new Brain 
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << RED << "Dog is destroyed!" << RESET << std::endl;
}

void Dog::makeSound() const {
	std::cout << YELLOW << " 🐶  Woof! Woof!" << RESET << std::endl;
}

// Accessors to Brain (for testing and encapsulation)

std::string const &Dog::getIdea(int index) const {
	return brain->getIdea(index);
}

void Dog::setIdea(int index, std::string const &idea) {
    brain->setIdea(index, idea);
}