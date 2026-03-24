#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

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

    std::cout << std::endl;
    std::cout << "-----------TESTING EX02 AForm-----------" << std::endl;
    std::cout << std::endl;

    std::srand(std::time(0));

    try
    {
        Bureaucrat gina("Gina", 1);
        Bureaucrat helen("Helen", 46);
        Bureaucrat ines("Ines", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Tiny Tin");
        PresidentialPardonForm pardon("Jane Doe");

        std::cout << "-----------Ines LOW grade-----------" << std::endl;

        ines.signForm(shrub);

        std::cout << "-----------Helen MEDIUM grade-----------" << std::endl;
        
        helen.signForm(shrub);
        helen.executeForm(shrub);

        helen.signForm(robot);
        helen.executeForm(robot);

        helen.signForm(pardon);
        helen.executeForm(pardon);

        std::cout << "-----------Gina HIGH grade-----------" << std::endl;

        gina.signForm(shrub);
        gina.executeForm(shrub);

        gina.signForm(robot);
        gina.executeForm(robot);

        gina.signForm(pardon);
        gina.executeForm(pardon);
    }
    catch (std::exception &error)
    {
        std::cout << "Exception caught: " << error.what() << std::endl;
    }

    return (0);
}