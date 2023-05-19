#include "AForm.hpp"

AForm::AForm(void): name("defacto"), sign(false), signGrade(150), execGrade(150)
{
	std::cout << "AForm Default Constructor Called" << std::endl;
}

AForm::AForm(int signGrade, int execGrade,  const std::string &name): name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooLowException();
	else if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooHighException();
	std::cout << "AForm Args Constructor Called" << std::endl;
}

AForm::AForm(const AForm &obj): name(obj.getName()), sign(obj.getSigned()), signGrade(obj.getSignGrade()), execGrade(obj.getExecGrade())
{
	std::cout << "AForm Copy Constructor Called" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm Destructor Called" << std::endl;
}

const AForm	&AForm::operator=(const AForm &obj)
{
	this->sign = obj.getSigned();
	std::cout << "AForm Copy Assignment Operator Called" << std::endl;
	return (*this);
}

const	char *AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade Too Low";
}

const	char *AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade Too High";
}

bool	AForm::getSigned(void) const
{
	return (this->sign);
}

int	AForm::getSignGrade(void) const
{
	return (this->signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (this->execGrade);
}

std::string	AForm::getName(void) const
{
	return (this->name);
}

void AForm::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();

	this->sign = true;
}

void	AForm::execute(const Bureaucrat &obj) const
{
	if (!sign || obj.getGrade() > this->execGrade)
		throw AForm::GradeTooLowException();
	doAction();
}

std::ostream	&operator<<(std::ostream &os, const AForm &obj)
{
	    return (os << "AForm name: " << obj.getName() << ", sign: " << obj.getSigned() << ", grade to sign: " \
			    << obj.getSignGrade() << ", grade to execute: " << obj.getExecGrade());
}
