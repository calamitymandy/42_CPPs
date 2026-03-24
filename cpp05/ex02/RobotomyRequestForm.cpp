#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

/* ================= CONSTRUCTORS, ASSIGNMENT & DESTRUCTOR ================= */
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("No Target") {}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target) {}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    if (this != &copy) {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

/* ================= EXECUTE ACTION ================= */
void RobotomyRequestForm::executeAction() const {
    std::cout << "Bzzzz... BZZZZZ.... Drilling noises..." << std::endl;

    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Failed to robotomize " << _target << "!" << std::endl;
}