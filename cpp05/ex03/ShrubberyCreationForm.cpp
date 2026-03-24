#include "ShrubberyCreationForm.hpp"
#include <fstream>

/* ================= CONSTRUCTORS, ASSIGNMENT & DESTRUCTOR ================= */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("No Target") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target) {}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    if (this != &copy) {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* ================= EXECUTE ACTION ================= */
void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((_target + "_shrubbery").c_str());

    if (file.is_open())
    {
        file << "\n";
        file << "        /\\        &&&        /\\        ////        /\\\n";
        file << "       ///\\      &&&&&      ///\\      ////\\\\\\     ///\\\n";
        file << "      ////\\\\      &&&      ////\\\\    ////\\\\\\\\    ////\\\\\n";
        file << "        ||         ||         ||         ||         ||\n";
        file << "\n";
        file << "    A pretty forest has been planted with all these forms!\n";
        file << "\n";

        file.close();
    }
}