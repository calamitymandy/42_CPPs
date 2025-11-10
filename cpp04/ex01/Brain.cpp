#include "Brain.hpp"
#include "Animal.hpp"

Brain::Brain() {
	std::cout << PURPLE << "🧠 Brain created" << RESET << std::endl;
}

// As ideas is a fixed-size array (std::string ideas[100];), not a std::array,
// you can’t actually copy-initialize and use the member initializer list
Brain::Brain(const Brain &copy) {
	std::cout << PURPLE << "🧠 Brain copied" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
}

Brain &Brain::operator=(const Brain &copy) {
	std::cout << PURPLE << "🧠 Brain assigned" << RESET << std::endl;
	if (this != &copy) {
		for (int i = 0; i < 100; i++)
	ideas[i] = copy.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << RED << "💀 Brain destroyed" << RESET << std::endl;
}

void Brain::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string const &Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return ideas[index];
	return ideas[0];
}