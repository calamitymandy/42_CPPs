#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        AForm();
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        virtual ~AForm();

        std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;
        void        beSigned(const Bureaucrat &bureaucrat);

        //Put all checks in AForm::execute() & call a pure virtual function for the actual action
        void            execute(Bureaucrat const &executor) const;
        virtual void    executeAction() const = 0;

        class GradeTooHighException : public std::exception {
            public: virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public: virtual const char *what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public: virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif