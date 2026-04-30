#include "Span.hpp"

Span::Span() : _maxSize(0) {}
Span::Span(unsigned int n) : _maxSize(n) {}
Span::Span(const Span &copy) {
    *this = copy;
}
Span &Span::operator=(const Span &copy) {
    if (this != &copy) {
        _data = copy._data;
        _maxSize = copy._maxSize;
    }
    return *this;
}
Span::~Span() {}

void Span::addNumber(int num) {
    if (_data.size() >= _maxSize)
        throw std::runtime_error("Cannot add more numbers, vector is full");
    _data.push_back(num);
}

int Span::shortestSpan() const {
    if (_data.size() < 2)
        throw std::runtime_error("Not enough elements to find a span");
    std::vector<int> sortedData(_data);
    std::sort(sortedData.begin(), sortedData.end());

    int shortest = sortedData[1] - sortedData[0];
    for (size_t i = 1; i < sortedData.size() -1; i++) {
        int diff = sortedData[i +1] - sortedData[i];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan() const {
    if (_data.size() < 2)
        throw std::runtime_error("Not enough elements to find a span");
    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());
    return max - min;
}