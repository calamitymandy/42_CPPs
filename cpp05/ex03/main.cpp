#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>
#include "Intern.hpp"

int main() {

    std::cout << "-----------TESTING EX03 Intern makeForm-----------" << std::endl;
    std::cout << std::endl;

    std::srand(std::time(0));

    try
    {
        std::cout << "-----------Creation Intern-----------" << std::endl;
        Intern bestIntern;

        std::cout << "-----------makeForm-----------" << std::endl;
        AForm *shrubForm = bestIntern.makeForm("shrubbery creation", "Alpha");
        AForm *robotForm = bestIntern.makeForm("robotomy request", "Beta");
        AForm *pardonForm = bestIntern.makeForm("presidential pardon", "Gamma");
        AForm *invalidForm = bestIntern.makeForm("unknown form", "Delta");

        std::cout << "-----------Signing and executing-----------" << std::endl;

        Bureaucrat jules("Jules", 1);
        Bureaucrat kenya("Kenya", 36);

        std::cout << "-----------Jules Grade 1-----------" << std::endl;
        jules.signForm(*shrubForm);
        jules.executeForm(*shrubForm);

        jules.signForm(*robotForm);
        jules.executeForm(*robotForm);

        jules.signForm(*pardonForm);
        jules.executeForm(*pardonForm);

        if (invalidForm)
        {
            jules.signForm(*invalidForm);
            jules.executeForm(*invalidForm);
        }

        std::cout << "-----------Kenya Grade 36-----------" << std::endl;
        kenya.signForm(*shrubForm);
        kenya.executeForm(*shrubForm);

        kenya.signForm(*robotForm);
        kenya.executeForm(*robotForm);

        kenya.signForm(*pardonForm);
        kenya.executeForm(*pardonForm);

        if (invalidForm)
        {
            kenya.signForm(*invalidForm);
            kenya.executeForm(*invalidForm);
        }

        delete shrubForm;
        delete robotForm;
        delete pardonForm;
        delete invalidForm;

    }
    catch (std::exception &error)
    {
        std::cout << "Exception caught: " << error.what() << std::endl;
    }
    return (0);
}