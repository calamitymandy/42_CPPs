#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
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