#include "PmergeMe.hpp"
#include <iostream>

/* a merge-insert hybrid sorting approach inspired by Ford-Johnson, 
combining recursive merge behavior with insertion sorting for small partitions.

insertion sort for small partitions performs very efficiently on very small datasets 
because it has low overhead and benefits from partially sorted data.

duplicates are allowed, we sort them as they are, without any special handling.

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