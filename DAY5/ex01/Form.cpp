#include "Form.hpp"

Form::Form(void): name("defacto"), sign(false), signGrade(150), execGrade(150)
{
	std::cout << "Form Default Constructor Called" << std::endl;
}

Form::Form(int signGrade, int execGrade,  const std::string &name): name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooLowException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooHighException();
	std::cout << "Form Args Constructor Called" << std::endl;
}

Form::Form(const Form &obj): name(obj.getName()), sign(obj.getSigned()), signGrade(obj.getSignGrade()), execGrade(obj.getExecGrade())
{
	std::cout << "Form Copy Constructor Called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form Destructor Called" << std::endl;
}

const Form	&Form::operator=(const Form &obj)
{
	this->sign = obj.getSigned();
	std::cout << "Form Copy Assignment Operator Called" << std::endl;
	return (*this);
}

const	char *Form::GradeTooLowException::what(void) const throw()
{
	return "Grade Too Low";
}

const	char *Form::GradeTooHighException::what(void) const throw()
{
	return "Grade Too High";
}

bool	Form::getSigned(void) const
{
	return (this->sign);
}

int	Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int	Form::getExecGrade(void) const
{
	return (this->execGrade);
}

std::string	Form::getName(void) const
{
	return (this->name);
}

void Form::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();

	this->sign = true;
}

std::ostream	&operator<<(std::ostream &os, const Form &obj)
{
	    return (os << "Form name: " << obj.getName() << ", sign: " << obj.getSigned() << ", grade to sign: " \
			    << obj.getSignGrade() << ", grade to execute: " << obj.getExecGrade());
}
