#include "Zombie.hpp"

int main() {

	// Heap allocation
	Zombie* heapZombie = newZombie("Heapster");
	heapZombie->announce();
	delete heapZombie; // Must delete to avoid memory leaks
	
	// Stack allocation
	randomChump("Stacky");
	
	return (0);
}