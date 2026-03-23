#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* ================= CONSTRUCTORS, ASSIGNMENT & DESTRUCTOR ================= */

Bureaucrat::Bureaucrat() : _name("No Name"), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}
    
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {}
    
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy)
        _grade = copy._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

/* ================= GETTERS ================= */
std::string Bureaucrat::getName() const {
    return _name;
}
int         Bureaucrat::getGrade() const {
    return _grade;
}

/* ================= GRADE & FORM MANAGEMENT ================= */
void    Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm &form) const {
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &error)
    {
        std::cout   << _name << " couldn't sign "
                    << form.getName()
                    << " because "
                    << error.what()
                    << std::endl;
    }
}

/* ================= EXCEPTIONS ================= */
const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

/* ================= OPERATOR OVERLOAD ================= */
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat){
    os  << bureaucrat.getName()
        << ", bureaucrat grade "
        << bureaucrat.getGrade();
    return os;
}
