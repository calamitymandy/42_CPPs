#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

// Define colors
#define RESET       "\033[0m"
#define RED         "\033[91m"
#define GREEN       "\033[92m"
#define YELLOW      "\033[93m"
#define ORANGE      "\033[38;5;209m"
#define GRAY        "\033[38;5;225m"
#define CYAN        "\033[96m"
#define PURPLE      "\033[95m"
#define ITALIC      "\033[3m"

/**
 * In C++, an interface is typically a class where all methods are pure virtual.
 * Right now AAnimal isn’t a pure interface because it also has state (type) and 
 * some implemented functions.
 * But it serves the same role conceptually — a common base to standardize behavior.
 */

class AAnimal {
	protected:
		std::string type;

	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		AAnimal &operator=(const AAnimal &copy);
		virtual ~AAnimal();                      // Must be virtual for proper cleanup

		std::string getType() const;

		// PURE virtual function => makes class ABSTRACT
		// In C++, a class becomes abstract when it contains at least one pure virtual function.
		// The = 0 makes it pure virtual — the base class provides no implementation, 
		// and derived classes must override it.
		virtual void makeSound() const = 0;
};

#endif