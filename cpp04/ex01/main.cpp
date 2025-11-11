#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main() {

    std::cout << "=== ONLY ANIMAL ===" << std::endl;
    const Animal *a = new Animal();
    a->makeSound();
    delete a; // If we don't delete we have a leak

    // Subtype Polymorphism: Base pointer calls derived behavior like:
    // Animal *a = new Dog(); a->makeSound();
    std::cout << std::endl;
    std::cout << "=== CREATING & USING ANIMAL, CAT, DOG OBJECTS ===" << std::endl;
    const Animal* animals[6];
    for (int i = 0; i < 2; i++) animals[i] = new Dog();
    for (int i = 2; i < 6; i++) animals[i] = new Cat();
    for (int i = 0; i < 6; i++) {
        std::cout << animals[i]->getType() << ":" << std::endl;
        animals[i]->makeSound();
    }
    for (int i = 0; i < 6; i++) delete animals[i];

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "=== COPY CONSTRUCTOR & ASIGNMENT OPERATOR ===" << std::endl;
    /** if the copy were shallow, both basic and tmp would point to the same Brain.
    When tmp is destroyed, its destructor would delete the Brain. Then, when basic 
    is destroyed, it would try to delete the same Brain again — causing a 
    double free or crash. */
    Dog basic;
    {
        Dog tmp = basic; // This should invoke the copy constructor
        tmp.setIdea(0, "Chase the mailman!");
        std::cout << "After copying, tmp's type: " << tmp.getType() << std::endl;
        tmp.makeSound();
        std::cout << "tmp idea[0]: " << tmp.getIdea(0) << std::endl;
    } // tmp goes out of scope here, should delete its own Brain
    
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "=== DEEP COPY ===" << std::endl;

    Dog dog1;
    dog1.setIdea(0, "Chase the mailman!");
    dog1.setIdea(1, "Eat bones!");

    Dog dog2 = dog1;  // Deep copy 
    std::cout << "Dog2 idea[0]: " << dog2.getIdea(0) << std::endl;

    std::cout << "--- We change Dog2 idea[0] to: Sleep all day ---" << std::endl;
    dog2.setIdea(0, "Sleep all day");

    std::cout << "Dog1 idea[0]: " << dog1.getIdea(0) << std::endl;
    std::cout << "Dog2 idea[1]: " << dog2.getIdea(1) << std::endl;
    std::cout << "Dog2 idea[0]: " << dog2.getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "=== CREATING & USING CAT OBJECTS WITH COPY ===" << std::endl;

    Cat originalCat;
    std::cout << "We set Original Cat ideas (no printing)" << std::endl;
    originalCat.setIdea(0, "oh a mouse");
    originalCat.setIdea(1, "let's chase the mouse");
    originalCat.setIdea(2, "We could eat it");
    originalCat.setIdea(3, "or is it a friend?");
    originalCat.setIdea(4, "so cute");

    // Deep copy of 'originalCat'
    Cat copyCat = originalCat; // This would call the copy constructor

    std::cout << "\nAfter copying:\n" << std::endl;
    std::cout << "Original Cat ideas:" << std::endl;
    std::cout << originalCat.getIdea(0) << " " 
    << originalCat.getIdea(1) << " " << originalCat.getIdea(2) << " " 
    << originalCat.getIdea(3) << " " << originalCat.getIdea(4) << std::endl;

    std::cout << "\nCopied Cat ideas:" << std::endl;
    std::cout << copyCat.getIdea(0) << " " 
    << copyCat.getIdea(1) << " " << copyCat.getIdea(2) << " " 
    << copyCat.getIdea(3) << " " << copyCat.getIdea(4) << std::endl;

    std::cout << "\nModifying ideas of the copy..." << std::endl;

    copyCat.setIdea(0, "WHAT DO YOU WANT?!");

    std::cout << "\nAfter modification:" << std::endl;

    std::cout << "\nOriginal Cat ideas:" << std::endl;
    std::cout << originalCat.getIdea(0) << " " 
    << originalCat.getIdea(1) << " " << originalCat.getIdea(2) << " " 
    << originalCat.getIdea(3) << " " << originalCat.getIdea(4) << std::endl;

    std::cout << "\nCopied Cat ideas:" << std::endl;
    std::cout << copyCat.getIdea(0) << " " 
    << copyCat.getIdea(1) << " " << copyCat.getIdea(2) << " " 
    << copyCat.getIdea(3) << " " << copyCat.getIdea(4) << std::endl;
    std::cout << std::endl;

    return 0;
}
