#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

/*std::stack is an adapter, not a real container.
Internally it contains a protected member:
container_type c;
That’s the underlying container (by default: std::deque<T>)

So the whole point is basically to expose iterators of the underlying container*/

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() {}
        MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
        MutantStack &operator=(const MutantStack &copy) {
            std::stack<T>::operator=(copy);
            return *this;
        }
        ~MutantStack() {}
};


#endif