#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

/*Standard Template Library (STL) is a collection of pre-built classes and functions 
providing ready-to-use, efficient algorithms and containers that make it easy 
to manage data using common data structures like vectors, stacks, and maps.

std::deque proves the template is truly generic STL-compatible function and not 
accidentally tailored  to one container type(like vector). 
std::find only requires input iterators and all three containers (vector/list/deque) 
support that.
*/

int main() {

    std::cout << "------- VECTOR -------" << std::endl;
    std::vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    try {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "---- CONST VECTOR ----" << std::endl;

    const std::vector<int> const_vec = vec;
    try {
        std::vector<int>::const_iterator it = easyfind(const_vec, 20);
        std::cout << "Found in const vector: " << *it << std::endl;
        std::vector<int>::const_iterator it2 = easyfind(const_vec, 8);
        std::cout << "Found in const vector: " << *it2 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "-------- LIST --------" << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);

    try {
        std::list<int>::iterator it1 = easyfind(lst, 5);
        std::cout << "Found in list: " << *it1 << std::endl;
        std::list<int>::iterator it2 = easyfind(lst, 45);
        std::cout << "Found in list: " << *it2 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "------- DEQUE --------" << std::endl;

    std::deque<int> deq;
    deq.push_back(36);
    deq.push_back(46);
    deq.push_back(56);

    try {
        std::deque<int>::iterator it1 = easyfind(deq, 36);
        std::cout << "Found in deque: " << *it1 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}