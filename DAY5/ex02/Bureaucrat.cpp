#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): name("defacto"), grade(150)
{
	std::cout << "Bureaucrat Default Constructor Called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat Destructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name), grade(grade)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	std::cout << "Bureaucrat Name/Grade Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.getName()), grade(obj.getGrade())
{
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
}

const Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	std::cout << "Bureaucrat Copy Assignment Operator Called" << std::endl;
	this->grade = obj.getGrade();
	return (*this);
}

const	char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade Too Low";
}

const	char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade Too High";
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

void	Bureaucrat::incGrade(void)
{
	if (--(this->grade) < 1)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::decGrade(void)
{
	if (++(this->grade) > 150)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::signForm(AForm &obj)
{
	try
	{
		obj.beSigned(*this);
		std::cout << this->name << " signed " << obj.getName() << std::endl;
	}
	catch (std::exception &e)
	{
        	std::cout << this->name << " cannot sign " << obj.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &obj)
{
	try
	{
		obj.execute(*this);
		std::cout << this->name << " executed " << obj.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn't execute the " << obj.getName() << " form, " << "becuase " << e.what() << std::endl;
	}

}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj)
{
	return (os << obj.getName() << ", bureaucrat grade " << obj.getGrade());
}
