#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

/*
std::stack is an adapter, not a real container.
Internally it contains a protected member:
container_type c;
That’s the underlying container (by default: std::deque<T>)
So the whole point is basically to expose iterators of the underlying container
and inheritance gives us access to the underlying container of std::stack

std::stack doesn’t provide iterators because it's designed as a restricted interface (LIFO only).
Iterators would break that abstraction.
*/

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() {}
        MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
        MutantStack &operator=(const MutantStack &copy) {
            if (this != &copy)
                std::stack<T>::operator=(copy);
            return *this;
        }
        ~MutantStack() {}

        /* Creating aliases for the iterators by accessing the iterators within the 
        underlying container type (deque by default) */
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        // Iterators & const iterators
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }

        // Reverse iterators & const reverse iterators
        reverse_iterator rbegin() { return this->c.rbegin(); }
        reverse_iterator rend() { return this->c.rend(); }
        const_reverse_iterator rbegin() const { return this->c.rbegin(); }
        const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif