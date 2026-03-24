#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

/*
** ===================== EX02 SUMMARY =====================
** Polymorphism and proper OOP design: Form becomes AForm (Abstract Form):
**    - Avoids code duplication
**    - Centralizes validation logic in AForm
**    - Delegates specific behavior to derived classes
**
** We now have multiple types of forms with different behaviors.
** The base class should not be instantiated, only used as a common interface.
**
** Key concepts:
**
** 1. Abstract Classes:
**    - AForm contains a pure virtual function:
**          virtual void executeAction() const = 0;
**    - This makes AForm abstract (cannot instantiate it).
**
** 2. Inheritance:
**    - Concrete forms inherit from AForm:
**          ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm
**
** 3. Polymorphism:
**    - Using AForm pointers/references allows calling different behaviors:
**          AForm* f = new RobotomyRequestForm("target");
**          f->execute(bureaucrat);
**
** 4. Template Method Pattern:
**    - AForm::execute() handles:
**          - checking if the form is signed
**          - checking executor grade
**    - Then calls:
**          executeAction()
**    - The derived classes implement only the specific action.
**
** ========================================================
*/

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

    std::cout << "-----------TESTING EX02 AForm-----------" << std::endl;
    std::srand(std::time(0));
    try
    {
        Bureaucrat gina("Gina", 1);
        Bureaucrat helen("Helen", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Tiny Tin");
        PresidentialPardonForm pardon("Jane Doe");

        helen.signForm(shrub);
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