#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750

/*int main(int, char**)
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

int main()
{
    Array<int> a(5);

    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i * 10;

    std::cout << "Original array:" << std::endl;
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << std::endl;

    std::cout << "\nCopy test:" << std::endl;
    Array<int> b = a;
    b[0] = 999;

    std::cout << "a[0] = " << a[0] << std::endl;
    std::cout << "b[0] = " << b[0] << std::endl;

    std::cout << "\nOut of bounds test:" << std::endl;
    try
    {
        std::cout << a[10] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught!" << std::endl;
    }

    return 0;
}