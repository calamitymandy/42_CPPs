#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain   *brain;

    public:
        Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        virtual ~Cat();

        virtual void makeSound() const;

        // Access to Brain’s ideas (optional but useful)
		std::string const &getIdea(int index) const;		// get method from brain
		void setIdea(int index, std::string const &idea);	// set method from brain
};

#endif