#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span
{
    private:
        std::vector<int> _data;
        unsigned int _maxSize;
    
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        ~Span();

        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;

        /*_data.insert(_data.end(), begin, end); inserts a sequence of elements 
        into the vector _data. _data.end() returns an iterator to the end of the vector, 
        which means the insertion happens after the last existing element.

        The begin and end parameters are iterator arguments describing the source range 
        of values to append. std::vector::insert uses that range to copy each element 
        from the range (begin, end) into _data.*/
        template <typename Iterator>
        void fillRange(Iterator begin, Iterator end) {
            if ((unsigned int)std::distance(begin, end) + _data.size() > _maxSize)
                throw std::runtime_error("Elements can't all fit in vector");
            _data.insert(_data.end(), begin, end);
        }
};

#endif