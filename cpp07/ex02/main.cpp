#include <iostream>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750

/*  Test all functionalities:
        - Default constructor → empty array
        - Sized constructor → array of given size, initialized to default values
        - Copy constructor → deep copy (no shared memory)
        - Assignment operator → deep copy, self-assignment safe
        - Destructor → no memory leaks
        - Subscript operator → read/write access with boundary checking
        - Size getter → returns correct size
        - Works with complex types (e.g., std::string)
        - Exception handling for out-of-bounds access
        - Const correctness → works with const arrays and const elements
*/
int main()
{
    std::cout << "===== EMPTY ARRAY TEST =====" << std::endl;
    Array<int> empty;
    std::cout << "Size: " << empty.size() << std::endl;

    std::cout << "\n===== INT ARRAY TEST (Sized constructor) =====" << std::endl;
    Array<int> arr(5);

    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i * 10; // shows read/write access

    std::cout << "Original array:" << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl; // shows read/write access

    std::cout << "\n===== COPY CONSTRUCTOR TEST (deep copy)=====" << std::endl;
    Array<int> copy(arr);
    copy[0] = 999;

    std::cout << "arr[0] = " << arr[0] << std::endl;
    std::cout << "copy[0] = " << copy[0] << std::endl;

    std::cout << "\n===== ASSIGNMENT OPERATOR TEST =====" << std::endl;
    Array<int> assign;
    assign = arr;
    assign[1] = 888;

    std::cout << "arr[1] = " << arr[1] << std::endl;
    std::cout << "assign[1] = " << assign[1] << std::endl;

    std::cout << "\n===== CONST ARRAY TEST =====" << std::endl;
    const Array<int> constArr(arr);
    for (unsigned int i = 0; i < constArr.size(); i++)
        std::cout << constArr[i] << std::endl; // must work

    std::cout << "\n===== OUT OF BOUNDS TEST =====" << std::endl;
    try
    {
        std::cout << arr[10] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught (high index)" << std::endl;
    }

    try
    {
        std::cout << arr[-1] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught (negative index)" << std::endl;
    }

    std::cout << "\n===== STRING ARRAY TEST (COMPLEX TYPE) =====" << std::endl;
    Array<std::string> strArr(3);

    strArr[0] = "Hello";
    strArr[1] = "You";
    strArr[2] = "!";

    for (unsigned int i = 0; i < strArr.size(); i++)
        std::cout << strArr[i] << std::endl;

    std::cout << "\n===== DEEP COPY WITH STRING =====" << std::endl;
    Array<std::string> strCopy(strArr);
    strCopy[0] = "Changed";

    std::cout << "Original - strArr[0]: " << strArr[0] << std::endl;
    std::cout << "Original - strArr[1]: " << strArr[1] << std::endl;
    std::cout << "Copy - strCopy[0]: " << strCopy[0] << std::endl;
    std::cout << "Copy - strCopy[1]: " << strCopy[1] << std::endl;

    return 0;
}
/**/

/*  Main of the subject: 2 Test of throw exceptions:
        case 1: -2 → converted to unsigned int so it becomes a huge positive number. 
        condition index >= _size → true → throws exception
        case 2: MAX_VAL → index is exactly equal to _size → condition index >= _size → true → throws exception
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/