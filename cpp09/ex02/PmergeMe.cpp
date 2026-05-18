#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <ctime>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &copy) { *this = copy; }
PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
    if (this != &copy) {
        _vector = copy._vector;
        _deque = copy._deque;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

// Validate if the string is a valid positive integer
bool PmergeMe::isValidNumber(const std::string &str) const {
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

// Convert a string to an integer, throwing an exception if the conversion fails
int PmergeMe::stringToInt(const std::string &str) const {
    std::stringstream strstr(str);
    long value;
    strstr >> value; // Use long to check for overflow. >> operator attempts to convert the string to a long integer and stores the result in value.
    if (strstr.fail() || !strstr.eof() || value < 0 || value > INT_MAX) // Check if conversion failed, if there are extra characters, or if the value is out of range for a positive integer
        throw std::runtime_error("Error: invalid number => " + str);
    return static_cast<int>(value); // Return the converted integer if all checks passed
}

// Parse input from command line arguments, validating each number and storing them in both the vector and deque
void PmergeMe::parseInput(char **argv) {
    for (int i = 1; argv[i]; i++) {
        std::string str(argv[i]);
        if (!isValidNumber(str))
            throw std::runtime_error("Error: invalid input => " + str);
        int number = stringToInt(str);
        _vector.push_back(number);
        _deque.push_back(number);
    }
}

// Print the original unsorted sequence
void PmergeMe::printBefore() const {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); i++) { // Both _vector and _deque contain the same elements, so we can use either to print the original sequence
        std::cout << _vector[i] << " "; // Print each number followed by a space
    }
    std::cout << std::endl;
}

// Print the sorted sequence after processing
void PmergeMe::printAfter() const {
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); i++) { // Both _vector and _deque should be sorted at this point, so we can use either to print the sorted sequence
        std::cout << _vector[i] << " "; // Print each number followed by a space
    }
    std::cout << std::endl;
}

// Process the sorting of both the vector and deque, measuring the time taken for each and printing the results
void PmergeMe::process() {
    printBefore();
    clock_t startVector = clock();
    mergeInsertSortVector(_vector);
    clock_t endVector = clock();
    clock_t startDeque = clock();
    mergeInsertSortDeque(_deque);
    clock_t endDeque = clock();
    printAfter(); // Print the sorted sequence after processing
    double vecTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000; // Convert clock ticks to microseconds
    double deqTime = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000; // Convert clock ticks to microseconds
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << vecTime << " microseconds" << std::endl; // Print the time taken to sort the vector
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << deqTime << " microseconds" << std::endl; // Print the time taken to sort the deque
}

// Sort the vector using a merge-insert hybrid sorting approach
void PmergeMe::mergeInsertSortVector(std::vector<int> &vec) {
    if (vec.size() <= 10) { // For small partitions, use insertion sort
        insertIntoSortedVector(vec);
        return;
    }
    size_t mid = vec.size() / 2; // Split the vector into two halves
    std::vector<int> left(vec.begin(), vec.begin() + mid);  // Create a left vector containing the first half of the original vector
    std::vector<int> right(vec.begin() + mid, vec.end());   // Create a right vector containing the second half of the original vector
    mergeInsertSortVector(left);    // Recursively sort the left half
    mergeInsertSortVector(right);   // Recursively sort the right half
    mergeVectors(vec, left, right); // Merge the sorted halves back into the original vector
}

// Sort the deque using a merge-insert hybrid sorting approach
void PmergeMe::mergeInsertSortDeque(std::deque<int> &deq) {
    if (deq.size() <= 10) { // For small partitions, use insertion sort
        insertIntoSortedDeque(deq);
        return;
    }
    size_t mid = deq.size() / 2; // Split the deque into two halves
    std::deque<int> left(deq.begin(), deq.begin() + mid);  // Create a left deque containing the first half of the original deque
    std::deque<int> right(deq.begin() + mid, deq.end());   // Create a right deque containing the second half of the original deque
    mergeInsertSortDeque(left);    // Recursively sort the left half
    mergeInsertSortDeque(right);   // Recursively sort the right half
    mergeDeques(deq, left, right); // Merge the sorted halves back into the original deque
}

// Insert elements into the sorted vector using insertion sort
void PmergeMe::insertIntoSortedVector(std::vector<int> &vec) {
    for (size_t i = 1; i < vec.size(); i++) { // Start from the second element and iterate through the vector
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) { // Move elements that are greater than key to one position ahead of their current position
            vec[j + 1] = vec[j]; // Shift the element at index j to index j + 1
            j--; // Move to the previous index
        }
        vec[j + 1] = key; // Insert the key at its correct position in the sorted subarray
    }
}

// Insert elements into the sorted deque using insertion sort
void PmergeMe::insertIntoSortedDeque(std::deque<int> &deq) {
    for (size_t i = 1; i < deq.size(); i++) { // Start from the second element and iterate through the deque
        int key = deq[i];
        int j = i - 1;
        while (j >= 0 && deq[j] > key) { // Move elements that are greater than key to one position ahead of their current position
            deq[j + 1] = deq[j]; // Shift the element at index j to index j + 1
            j--; // Move to the previous index
        }
        deq[j + 1] = key; // Insert the key at its correct position in the sorted subarray
    }
}

// Merge two sorted vectors into a single sorted vector
void PmergeMe::mergeVectors(std::vector<int> &vec, std::vector<int> &left, std::vector<int> &right) {
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) { // Merge elements from left and right vectors until one of them is exhausted
        if (left[i] < right[j])
            vec[k++] = left[i++]; // If the current element in left is smaller, add it to the merged vector and move to the next element in left
        else
            vec[k++] = right[j++]; // If the current element in right is smaller or equal, add it to the merged vector and move to the next element in right
    }
    while (i < left.size()) 
        vec[k++] = left[i++];   // If there are remaining elements in left, add them to the merged vector
    while (j < right.size()) 
        vec[k++] = right[j++];  // If there are remaining elements in right, add them to the merged vector
}

// Merge two sorted deques into a single sorted deque
void PmergeMe::mergeDeques(std::deque<int> &deq, std::deque<int> &left, std::deque<int> &right) {
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) { // Merge elements from left and right deques until one of them is exhausted
        if (left[i] < right[j])
            deq[k++] = left[i++]; // If the current element in left is smaller, add it to the merged deque and move to the next element in left
        else
            deq[k++] = right[j++]; // If the current element in right is smaller or equal, add it to the merged deque and move to the next element in right
    }
    while (i < left.size()) 
        deq[k++] = left[i++];   // If there are remaining elements in left, add them to the merged deque
    while (j < right.size()) 
        deq[k++] = right[j++];  // If there are remaining elements in right, add them to the merged deque
}
