#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "Wrong Cat";
    std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
    std::cout << "WrongCat copied" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
    if (this != &copy)
        WrongAnimal::operator=(copy);
    std::cout << "WrongCat assignement operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "We'll never hear that sound" << std::endl;
}