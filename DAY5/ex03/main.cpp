#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Intern i1;
		AForm *f1;

		std::cout << "robotomy request here" << std::endl;
		f1 = i1.makeForm("robotomy request", "jack");
		std::cout << *f1 << std::endl;
		delete f1;
		std::cout << std::endl;
		std::cout << "presidential request here" << std::endl;
		f1 = i1.makeForm("presidential request", "jack");
		std::cout << *f1 << std::endl;
		delete f1;
		std::cout << std::endl;
		std::cout << "shrubbery request here" << std::endl;
		f1 = i1.makeForm("shrubbery request", "jack");
		std::cout << *f1 << std::endl;
		delete f1;
		std::cout << std::endl;
		std::cout << "unknown request here" << std::endl;
		f1 = i1.makeForm("unknown request", "jack");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
