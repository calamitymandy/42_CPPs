#include "Zombie.hpp"

/* Stack object: automatic storage, destroyed automatically. (not pointer)
 * Heap object: dynamic storage, survives until you delete it. (pointer)
 */


int main() {
    std::cout << "----------HEAP----------" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;
    
    std::cout << "---------STACK----------" << std::endl;
    randomChump("StackZombie");

    return 0;
}


/*
int main() {

	std::cout << "----------HEAP----------" << std::endl;
	Zombie* heapZombie = newZombie("Heapheapheap hurrah");
	heapZombie->announce();
	delete heapZombie; // Must delete to avoid memory leaks
	
	std::cout << "---------STACK----------" << std::endl;
	randomChump("Stackatakata");

	std::cout << "----------UB----------" << std::endl;
	// Undefined behavior: trying to use heapZombie pointer after destruction
	std::cout << "Undefined behavior: trying to use heapZombie pointer after destruction" << std::endl;
	heapZombie->announce();
	std::cout << std::endl;
	
	return (0);
}
*/

/*
int main() {

	std::cout << "---------STACK----------" << std::endl;
	Zombie* pointerDirStackZombie = NULL;

	{
		Zombie stackZombie = Zombie("stackZombie");
		pointerDirStackZombie = &stackZombie; // keep the direction of the object in stack
		stackZombie.announce(); // Valid call within scope
	} // Zombie is destroyed here

	// Undefined behavior: trying to use stackZombie pointer after it goes out of scope
	// After stackZombie is destroyed, the memory it used may not yet have been overwritten.
	// So when we call announce(), it is reading leftover bytes still sitting there.
	std::cout << "----------UB----------" << std::endl;
	std::cout << "Undefined behavior: trying to use stackZombie pointer after it goes out of scope" << std::endl;
	pointerDirStackZombie->announce();
	std::cout << std::endl;
}
*/