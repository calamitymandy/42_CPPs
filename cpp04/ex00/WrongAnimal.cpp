#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    type = "Wrong Animal";
    std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type(copy.type) {
    std::cout << "WrongAnimal copied" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
    if (this != &copy)
        type = copy.type;
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed" << std::endl;
}


std::string WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::makeSound() const {
    std::cout << "🙃 Some unknown sound..." << std::endl;
}