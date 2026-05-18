#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);
        ~PmergeMe();

        void parseInput(char **argv);
        void process();
    
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

        bool isValidNumber(const std::string &str) const;   // Validate if the string is a valid positive integer
        int  stringToInt(const std::string &str) const;     // Convert a string to an integer, throwing an exception if the conversion fails
        void mergeInsertSortVector(std::vector<int> &vec);  // Sort the vector using a merge-insert hybrid sorting approach
        void mergeInsertSortDeque(std::deque<int> &deq);    // Sort the deque using a merge-insert hybrid sorting approach
        void insertIntoSortedVector(std::vector<int> &vec); // Insert elements into the sorted vector using insertion sort
        void insertIntoSortedDeque(std::deque<int> &deq);   // Insert elements into the sorted deque using insertion sort
        void mergeVectors(std::vector<int> &vec,std::vector<int> &left, std::vector<int> &right);    // Merge two sorted vectors into a single sorted vector
        void mergeDeques(std::deque<int> &deq, std::deque<int> &left, std::deque<int> &right);       // Merge two sorted deques into a single sorted deque
        void printBefore() const;   // Print the original unsorted sequence
        void printAfter() const;    // Print the sorted sequence after processing
};

#endif