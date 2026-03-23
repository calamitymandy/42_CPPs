#include "Bureaucrat.hpp"
#include "Form.hpp"

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

    std::cout << "-----------FORM TESTING-----------" << std::endl;

    Bureaucrat doula("Doula", 31);
    Bureaucrat elo("Elo", 1);
    Bureaucrat fiona("Fiona", 2);

    Form formOne("Form1", 30, 10);

    doula.signForm(formOne); // should fail
    std::cout << formOne << std::endl;
    std::cout << "----------------------" << std::endl;

    elo.signForm(formOne); //should succeed
    std::cout << formOne << std::endl;
    std::cout << "----------------------" << std::endl;

    fiona.signForm(formOne); //should succeed
    std::cout << formOne << std::endl;

    return (0);
}