#include "Bureaucrat.hpp"

int main(void)
{
	{
		Bureaucrat b1;
		Bureaucrat b2("b2", 150);

		b1 = b2;

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
	}
	{
		Bureaucrat b2("b2", 150);
		Bureaucrat b1(b2);


		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		try
		{
			b2.decGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat b2("b2", -1);
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
