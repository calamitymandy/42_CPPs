#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << std::endl << "=== CORRECT POLYMORPHISM ===" << std::endl;
    const Animal *meta = new Animal();
    std::cout << meta->getType() << " says: " << std::endl;
    meta->makeSound();
    delete meta;
    std::cout << std::endl;

    const Animal *dog = new Dog();
    std::cout << dog->getType() << " says: " << std::endl;
    dog->makeSound();
    delete dog;
    std::cout << std::endl;

    const Animal *cat = new Cat();
    std::cout << cat->getType() << " says: " << std::endl;
    cat->makeSound();
    delete cat;

    std::cout << std::endl << "=== CORRECT POLYMORPHISM: POINTER ARRAY ===" << std::endl;
    Animal  *animals[3];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Animal();

    for (int i = 0; i < 3; i++) {
        animals[i]->makeSound();
        delete animals[i];
    }

    /*When you delete an object through a pointer to the base class, C++ looks up 
    which destructor to call using polymorphism.
    
    However, polymorphism only works with virtual functions.

    So: wrong is a pointer of type WrongAnimal*
    We call delete wrong;
    Because WrongAnimal::~WrongAnimal() is not virtual, the compiler will not call 
    WrongCat::~WrongCat().

    As a result:
    Only the base class destructor (WrongAnimal destroyed) runs.
    The derived class destructor (WrongCat destroyed) is never executed.*/
    
    std::cout << std::endl << "=== WRONG POLYMORPHISM ===" << std::endl;
    const WrongAnimal *wrong = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();

    std::cout << RED << wrongCat->getType() << " says: " << RESET << ITALIC << std::endl;

    wrong->makeSound();
    wrongCat->makeSound(); // ⚠️ Calls WrongAnimal::makeSound() instead of WrongCat’s
    std::cout << RESET << RED << "This is not expected behavior!" << RESET << std::endl;

    delete wrong;
    delete wrongCat;

    return 0;
}
