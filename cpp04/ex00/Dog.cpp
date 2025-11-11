#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << CYAN << "Dog is created!" << RESET << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	std::cout << "Dog is copied" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {
	if (this != &copy)
		Animal::operator=(copy);
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << RED << "Dog is destroyed!" << RESET << std::endl;
}

void Dog::makeSound() const {
	std::cout << YELLOW << " 🐶  Woof! Woof!" << RESET << std::endl;
}