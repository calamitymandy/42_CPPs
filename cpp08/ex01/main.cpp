#include <iostream>
#include <cstdlib>
#include <vector>
#include "span.hpp"

int main() {
    std::cout << "===== SUBJECT TEST =====" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== OVERFLOW TEST =====" << std::endl;
    try {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4); // Should throw an exception
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== SMALL SIZE TEST =====" << std::endl;
    try {
        Span sp(1);
        sp.addNumber(42);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Should throw an exception
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== LARGE TEST (10000) =====" << std::endl;
    try {
        Span big(10000);
        for (int i = 0; i < 10000; i++) {
            big.addNumber(rand());
        }
        std::cout << "Shortest Span: " << big.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << big.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== RANGE TEST =====" << std::endl;
    try {
        Span sp(10);
        std::vector<int> nums;
        nums.push_back(5);
        nums.push_back(3);
        nums.push_back(8);
        nums.push_back(1);
        nums.push_back(4);

        sp.fillRange(nums.begin(), nums.end());
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}