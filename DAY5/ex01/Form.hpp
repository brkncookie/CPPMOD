#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		const std::string name;
		bool	signed;
		const int	signGrade;
		const int	execGrade;
	public:
		Form(void);
		~Form(void);
		Form(const Form &obj);
		Form(int signGrade, int signExec, const std::string &name);
		const Form	&operator=(const Form &obj);

		bool	getSigned(void) const;
		int	getSignGrade(void) const;
		int	getExecGrade(void) const;
		std::string	getName(void) const;

		void	beSigned(const Bureaucrat &obj);

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what(void) const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Form &obj);
