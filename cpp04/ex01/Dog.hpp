#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain   *brain;

	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &copy);
		virtual ~Dog();

		virtual void makeSound() const;

		// Access to Brain’s ideas (optional but useful)
		std::string const &getIdea(int index) const;		// get method from brain
		void setIdea(int index, std::string const &idea);	// set method from brain
};

#endif