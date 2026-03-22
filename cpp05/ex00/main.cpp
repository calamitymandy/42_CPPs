#include "Bureaucrat.hpp"

int main() {
    try
    {
        Bureaucrat alba("Alba", 2);
        std::cout << alba << std::endl;

        alba.incrementGrade();
        std::cout << alba << std::endl;

        alba.incrementGrade(); //should throw
    }
    catch(const std::exception &error)
    {
        std::cout << "Exception caught: " << error.what() << '\n';
    }

    std::cout << "----------------------" << std::endl;

    try
    {
        Bureaucrat bella("Bella", 151);  // invalid grade
        std::cout << bella << std::endl; // this will not show bc of invalid grade at start
    }
    catch(const std::exception &error)
    {
        std::cout << "Exception caught: " << error.what() << '\n';
    }   

    std::cout << "----------------------" << std::endl;

    try
    {
        Bureaucrat celia("Celia", 150);
        std::cout << celia << std::endl;

        celia.decrementGrade(); //should throw
    }
    catch (std::exception &error)
    {
        std::cout << "Exception caught: " << error.what() << std::endl;
    }
    return (0);
}