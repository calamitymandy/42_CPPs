#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* ================= CONSTRUCTORS, ASSIGNMENT & DESTRUCTOR ================= */
AForm::AForm() : _name("No Name"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) 
    :   _name(name), _isSigned(false),
        _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
            throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
            throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

AForm &AForm::operator=(const AForm &copy) {
    if (this != &copy)
        _isSigned = copy._isSigned;
    return *this;
}

AForm::~AForm() {}

/* ================= GETTERS ================= */
std::string AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

/* ================= LOGIC beSigned ================= */
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

/* ================= LOGIC EXECUTE ================= */

void AForm::execute(Bureaucrat const &executor) const {
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
}

/* ================= EXCEPTIONS ================= */
const char *AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high";
}
const char *AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low";
}
const char *AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

/* ================= OPERATOR ================= */
std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
    os  << "Form " << AForm.getName()
        << " -> signed: " << (AForm.getIsSigned() ? "yes" : "no")
        << " - grade to sign: " << AForm.getGradeToSign()
        << " - grade to execute: " << AForm.getGradeToExecute();
    return os;
}