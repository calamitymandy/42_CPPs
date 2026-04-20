#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // for size_t
#include <iostream>
#include <string>

// NON-CONST array version
template <typename T>
void iter(T *array, const size_t length, void(*func)(T &)) {
    if (!array || !func)
        return ;
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

// CONST array version
template <typename T>
void iter(const T *array, const size_t length, void(*func)(const T &)) {
    if (!array || !func)
        return ;
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

/*
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}
*/
#endif