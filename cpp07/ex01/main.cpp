#include "iter.hpp"
#include <iostream>
#include <string>

/* 
Templates are a blueprint that the compiler uses to build real functions 
depending on the types you use.

    1. Generic programming: Write one function → works for all types
    2. Template instantiation: Compiler generates real functions from templates
    3. Const correctness -> Handling:T andconst T
    4. Function pointers: Passing behavior as argument
    5. Type constraints (implicit): Your template works only if:
        - the function matches the type
        - operations are valid

Needs to be supporting both const and non-const arrays correctly.
   So we need two overloads of iter:
        For non-const arrays
        For const arrays

*/

// Non-const function to be applied to non-const array elements
template <typename T>
void increment(T &element) {
    element += 1;
}

// Const function to be applied to const array elements
template <typename T>
void print(const T &element) {
    std::cout << element << std::endl;
}

int main(void) {

    int intArray[5] = {1, 2, 3, 4, 5};
    std::cout << "Original int array:" << std::endl;
    iter(intArray, 5, print<int>);

    std::cout << "\n-----\n" << std::endl;

    iter(intArray, 5, increment<int>);
    //iter(intArray, 5, increment<int>);
    std::cout << "Incremented int array:" << std::endl;
    iter(intArray, 5, print<int>);

    std::cout << "\n-----\n" << std::endl;

    std::string strArray[3] = {"Hello", "you", "!"};
    std::cout << "Print string array:" << std::endl;
    iter(strArray, 3, print<std::string>);

    return 0;
}

/*
int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  const int len = 5;

  iter( tab, len, print<const int> );
  iter( tab2, len, print<Awesome> );

  return 0;
}
*/