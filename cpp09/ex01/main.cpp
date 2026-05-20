#include "RPN.hpp"
#include <iostream>

/* Reverse Polish Notation example : a × (b + c) becomes: a b c + ×

stack is ideal for reverse Polish Notation, because RPN works naturally with a stack. 
RPN evaluation requires last-in-first-out behavior.

Each number is pushed onto the stack, and each operator pops the last two operands, 
computes the result, then pushes it back.*/

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " \"expression\"" << std::endl;
        return 1;
    }

    RPN rpn;
    try {
        std::cout << rpn.evaluate(argv[1]) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}