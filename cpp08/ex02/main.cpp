#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main() {
    std::cout << "===== SUBJECT TEST =====" << std::endl;
    
    // Basic usage (same as subject)
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    // top() should return last pushed element
    std::cout << "Top element: " << mstack.top() << std::endl; // 17
    mstack.pop();

    // size should now be 1
    std::cout << "Size after pop: " << mstack.size() << std::endl; // 1

    mstack.push(3);
    std::cout << "Size after push: " << mstack.size() << std::endl; // 2

    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "Size after push: " << mstack.size() << std::endl; // 5

    std::cout << "\n===== ITERATION TEST =====" << std::endl; 
    
    // Iterate through MutantStack using iterators
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "Elements in MutantStack: " << std::endl;
    for (; it != ite; ++it) {
        std::cout << *it << std::endl;
    }
    
    std::cout << "\n===== REVERSE ITERATION TEST =====" << std::endl;

    // Iterate in reverse using reverse iterators
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    std::cout << "Elements in reverse: " << std::endl;
    for (; rit != rite; ++rit) {
        std::cout << *rit << std::endl;
    }

    std::cout << "\n===== COPY TEST =====" << std::endl;
    // Test copy constructor
    MutantStack<int> copyStack(mstack);
    std::cout << "Elements in copied MutantStack: " << std::endl;
    for (MutantStack<int>::iterator it = copyStack.begin(); it != copyStack.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "\n===== ASSIGNMENT TEST =====" << std::endl;
    // Test assignment operator
    MutantStack<int> assignedStack;
    assignedStack = mstack;
    std::cout << "Elements in assigned MutantStack: " << std::endl;
    for (MutantStack<int>::iterator it = assignedStack.begin(); it != assignedStack.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "\n===== COMPARISON WITH std::list =====" << std::endl;
    // Compare with std::list to show similar behavior
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);

    std::cout << "List back: " << lst.back() << std::endl;
    
    lst.pop_back();
    
    std::cout << "List size after pop: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "Elements in std::list: " << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "\n===== STACK COMPATIBILITY TEST =====" << std::endl;
    // MutantStack should behave like std::stack
    std::stack<int> normalStack(mstack); // Should work since MutantStack inherits from std::stack
    std::cout << "Top of std::stack initialized with MutantStack: " << normalStack.top() << std::endl; // Should be 0
    
    return 0;
}