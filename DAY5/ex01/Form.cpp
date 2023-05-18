#include "Form.hpp"

Form::Form(void): name("defacto"), signed(false), signGrade(150), gradeExec(150)
{
	std::cout << "Form Default Constructor Called" << std::endl;
}

Form::Form(int signGrade, int gradeExec,  std::string &name): name(name), signed(false), signGrade(signGrade), gradeExec(gradeExec)
{
	if (signGrade < 1 || gradeExec < 1)
		throw Form::GradeTooLowException();
	else if (signGrade > 150 || gradeExec > 150)
		throw Form::GradeTooHighException();
	std::cout << "Form Args Constructor Called" << std::endl;
}

Form::Form(const Form &obj): name(obj.getName()), signed(obj.getSigned()), signGrade(obj.getSignGrade()), gradeExec(obj.getSignExec())
{
	std::cout << "Form Copy Constructor Called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form Destructor Called" << std::endl;
}

const Form	&Form::operator=(const Form &obj)
{
	this->signed = obj.getSigned();
	std::cout << "Form Copy Assignment Operator Called" << std::endl;
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
	return (this->signed);
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

void beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();

	this->signed = true;
}

std::ostream	&operator<<(std::ostream &os, const Form &obj)
{
	    return (os << "Form name: " << src.getName() << ", signed: " << src.getSigned() << ", grade to sign: " \
			    << src.getSignGrade() << ", grade to execute: " << src.getExecGrade());
}
