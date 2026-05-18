#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cstdlib>

RPN::RPN() {}
RPN::RPN(const RPN &copy) { *this = copy; }
RPN &RPN::operator=(const RPN &copy) {
    if (this != &copy)
        _stack = copy._stack;
    return *this;
}
RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::calculate(int a, int b, char sign) const {
    switch (sign) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) //
                throw std::runtime_error("Error: division by zero.");
            return a / b;
    }
    throw std::runtime_error("Error: unknown operator.");
}

int RPN::evaluate(const std::string &expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) { // Read tokens from the input one by one. >> operator automatically skips whitespace and reads until the next whitespace, giving us individual tokens (numbers or operators).
        if (token.length() == 1 && std::isdigit(token[0])) { // Check if token is a single digit
            _stack.push(token[0] - '0'); // Convert char digit to int and push onto stack
        }
        else if (isOperator(token)) { // Check if token is an operator
            if (_stack.size() < 2) // Not enough operands for the operator
                throw std::runtime_error("Error: insufficient operands.");
            int b = _stack.top();   // Get the top operand
            _stack.pop();           // Pop the top operand
            int a = _stack.top();   // Get the next operand
            _stack.pop();           // Pop the next operand
            _stack.push(calculate(a, b, token[0]));     // Calculate the result of applying the operator to the operands and push it back onto the stack
        } else {
                throw std::runtime_error("Error: invalid token.");
        }
    }

    if (_stack.size() != 1) // After processing all tokens, there should be exactly one result on the stack
        throw std::runtime_error("Error: invalid expression.");
    return _stack.top();
}