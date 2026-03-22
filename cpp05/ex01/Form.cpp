#include "Form.hpp"
#include "Bureaucrat.hpp"

/* ================= CONSTRUCTORS, ASSIGNMENT & DESTRUCTOR ================= */
Form::Form() : _name("No Name"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) 
    :   _name(name), _isSigned(false),
        _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
            throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
            throw GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

Form &Form::operator=(const Form &copy) {
    if (this != &copy)
        _isSigned = copy._isSigned;
    return *this;
}

Form::~Form() {}

/* ================= GETTERS ================= */
std::string Form::getName() const { 
    return _name;
}
bool        Form::getIsSigned() const {
    return _isSigned;
}
int         Form::getGradeToSign() const {
    return _gradeToSign;
}
int         Form::getGradeToExecute() const {
    return _gradeToExecute;
}

/* ================= LOGIC beSigned ================= */
void        Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

/* ================= EXCEPTIONS ================= */
const char *Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high";
}
const char *Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low";
}

/* ================= OPERATOR ================= */
std::ostream &operator<<(std::ostream &os, const Form &form) {
    os  << "Form " << form.getName()
        << " -> signed: " << (form.getIsSigned() ? "yes" : "no")
        << " - grade to sign: " << form.getGradeToSign()
        << " - grade to execute: " << form.getGradeToExecute();
    return os;
}