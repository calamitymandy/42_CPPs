#include "PmergeMe.hpp"
#include <iostream>

/* a merge-insert sorting approach inspired by Ford-Johnson, 
combining recursive merge behavior with insertion sorting for small partitions.
(insertion sort for small partitions performs very efficiently on very small datasets 
because it has low overhead and benefits from partially sorted data.)

duplicates are allowed, we sort them as they are, without any special handling.

The Ford-Johnson algorithm operates through a series of steps that involve 
pairing elements and using binary search for insertion. 
Here’s a simplified breakdown of its process:

Initial Pairing: The algorithm begins by pairing elements and sorting these pairs.
Recursive Sorting: It recursively sorts these pairs until no further pairs can be formed.
Insertion: After sorting, the remaining elements are inserted into the sorted list using 
a binary search method, which is most efficient when the length of the subsequence 
is one less than a power of two.

Insertion Order
The insertion order is crucial for optimizing the number of comparisons. 
The algorithm uses a specific sequence, known as the Jacobsthal sequence, 
to determine this order. The way Jacobsthal numbers dictate the order of insertion is like this:
we start from the Jacobsthal number of 3. We start insertion from element b3. We insert elements in the reverse order starting from this element, until we hit b element of number of previous Jacobsthal number. In other words, the amount of inserted elements is current_jacobsthal - previous_jacobsthal.
For the Jacobsthal number of 3, we insert 2 elements (3 - 1)
For the Jacobsthal number of 5, we insert 2 elements (5 - 3)
For the Jacobsthal number of 11, we insert 6 elements (11 - 5)

I used vector and deque because both provide random access iterators, 
which are useful for recursive splitting and merging operations.

Vector uses contiguous memory, while deque uses segmented storage, 
allowing comparison of different container behaviors and performance.

std::vector stores elements contiguously in memory, 
giving excellent cache locality and fast random access.

std::deque also provides random access but uses segmented memory blocks, 
which may behave differently performance-wise.

Why not use std::sort? The subject explicitly asks for a merge-insert sorting implementation, 
so I implemented my own recursive hybrid sorting algorithm instead of using STL sorting algorithms.
*/

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <numbers...>" << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter;
        sorter.parseInput(argv);
        sorter.process();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}