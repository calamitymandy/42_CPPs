#include "BitcoinExchange.hpp"
#include <iostream>

/*
Why std::map?

I used std::map<std::string, double> because the keys are automatically sorted by date.
This allows me to efficiently find:
    - exact dates
    - or the closest lower date using lower_bound().
A map also provides logarithmic insertion and lookup complexity:
std::map is internally implemented as a balanced binary tree (usually a Red-Black Tree).
So instead of checking every element one by one, it repeatedly cuts the search space roughly in half.
*/

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;

    try
    {
        btc.loadData("data.csv");
        btc.processInput(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}