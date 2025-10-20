#include "Zombie.hpp"

/* Stack object: automatic storage, destroyed automatically. (not pointer)
 * Heap object: dynamic storage, survives until you delete it. (pointer)
 */

int main() {

	// Heap allocation
	Zombie* heapZombie = newZombie("Heapheapheap hurrah");
	heapZombie->announce();
	delete heapZombie; // Must delete to avoid memory leaks
	
	// Stack allocation
	randomChump("Stackatakata");

	// Undefined behavior: trying to use heapZombie pointer after destruction
	std::cout << "Undefined behavior: trying to use heapZombie pointer after destruction" << std::endl;
	heapZombie->announce();
	std::cout << std::endl;
	
	return (0);
}

/*
int main() {

	Zombie* pointerDirStackZombie = NULL;

	{
		Zombie stackZombie = Zombie("stackZombie");
		pointerDirStackZombie = &stackZombie; // keep the direction of the object in stack
		stackZombie.announce(); // Valid call within scope
	} // Zombie is destroyed here

	// Undefined behavior: trying to use stackZombie pointer after it goes out of scope
	std::cout << "Undefined behavior: trying to use stackZombie pointer after it goes out of scope" << std::endl;
	pointerDirStackZombie->announce();
	std::cout << std::endl;
}
*/