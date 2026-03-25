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
        helen.executeForm(pardon); // should fail bc not signed previously

        std::cout << "-----------Gina HIGH grade-----------" << std::endl;

        gina.signForm(shrub);
        gina.executeForm(shrub);

        gina.signForm(robot);
        gina.executeForm(robot);

        //gina.incrementGrade();

        gina.signForm(pardon);
        gina.executeForm(pardon);
    }
    catch (std::exception &error)
    {
        std::cout << "Exception caught: " << error.what() << std::endl;
    }

    return (0);
}