#include "Zombie.hpp"

/*
 * Stack object: automatic storage, destroyed automatically. (not pointer)
 * Heap object: dynamic storage, survives until you delete it. (pointer)
 */

int main() {

	// Heap allocation
	Zombie* heapZombie = newZombie("Heapster");
	heapZombie->announce();
	delete heapZombie; // Must delete to avoid memory leaks
	
	// Stack allocation
	randomChump("Stacky");
	
	return (0);
}