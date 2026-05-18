#include "PmergeMe.hpp"
#include <iostream>

/* a merge-insert hybrid sorting approach inspired by Ford-Johnson, 
combining recursive merge behavior with insertion sorting for small partitions.

std::vector stores elements contiguously in memory, 
giving excellent cache locality and fast random access.

std::deque also provides random access but uses segmented memory blocks, 
which may behave differently performance-wise.
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