#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

/* ================= CONSTRUCTORS, ASSIGNMENT & DESTRUCTOR ================= */
Intern::Intern() {}
Intern::Intern(const Intern &copy) { (void)copy;}
Intern &Intern::operator=(const Intern &copy) {
    (void)copy;
    return *this;
}
Intern::~Intern() {}

/* ================= FACTORY FUNCTIONS ================= */
static AForm *createShrubbery(const std:: string &target) {
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std:: string &target) {
    return new RobotomyRequestForm(target);
}

static AForm *createPresidential(const std:: string &target) {
    return new PresidentialPardonForm(target);
}

/* ================= MAIN FUNCTION ================= */
AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*functions[3])(const std::string&) = { createShrubbery, createRobotomy, createPresidential };

    for (int i = 0; i < 3; i++) {
        if (formName == names[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return functions[i](target);
        }
    }
    std::cout << "Intern can't create form with that name: " << formName << "... try again!" << std::endl;
    return NULL;
}