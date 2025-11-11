#include "AAnimal.hpp"

AAnimal::AAnimal() {
    type = "AAnimal";
    std::cout << GREEN << "AAnimal is created!" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : type(copy.type) {
    std::cout << "AAnimal is copied" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy) {
    if (this != &copy)
        type = copy.type;
    std::cout << "AAnimal assignment operator called" << std::endl;
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << RED << "AAnimal is destroyed!" << RESET << std::endl;
}

std::string AAnimal::getType() const {
    return type;
}

/*** remove the definition of makeSound() — since abstract classes can’t define pure virtuals normally ***

void AAnimal::makeSound() const {
    std::cout << GRAY << ITALIC << "The AAnimal makes a sound, but from which AAnimal is it?" << RESET << std::endl;
}
*/