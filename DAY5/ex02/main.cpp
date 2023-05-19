#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	std::cout << "				PresidentialPardonForm's Part" << std::endl;
	{
		PresidentialPardonForm p1;
		Bureaucrat b2("b2", 25);


		std::cout << p1 << std::endl;
		std::cout << b2 << std::endl;
		p1.beSigned(b2);
		std::cout << p1 << std::endl;
		b2.executeForm(p1);
	}
	{
		PresidentialPardonForm p1;
		Bureaucrat b2("b2", 5);


		std::cout << p1 << std::endl;
		std::cout << b2 << std::endl;
		p1.beSigned(b2);
		std::cout << p1 << std::endl;
		b2.executeForm(p1);
	}
	std::cout << "				ShrubberyCreationForm's Part" << std::endl;
	{
		ShrubberyCreationForm p1;
		Bureaucrat b2("b2", 145);


		std::cout << p1 << std::endl;
		std::cout << b2 << std::endl;
		p1.beSigned(b2);
		std::cout << p1 << std::endl;
		b2.executeForm(p1);
	}
	{
		ShrubberyCreationForm p1;
		Bureaucrat b2("b2", 100);


		std::cout << p1 << std::endl;
		std::cout << b2 << std::endl;
		p1.beSigned(b2);
		std::cout << p1 << std::endl;
		b2.executeForm(p1);
	}
	std::cout << "				RobotomyRequestForm Part" << std::endl;
	{
		RobotomyRequestForm p1;
		Bureaucrat b2("b2", 72);


		std::cout << p1 << std::endl;
		std::cout << b2 << std::endl;
		p1.beSigned(b2);
		std::cout << p1 << std::endl;
		b2.executeForm(p1);
	}
	{
		RobotomyRequestForm p1;
		Bureaucrat b2("b2", 45);


		std::cout << p1 << std::endl;
		std::cout << b2 << std::endl;
		p1.beSigned(b2);
		std::cout << p1 << std::endl;
		b2.executeForm(p1);
	}
}
