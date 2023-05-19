#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string name;
		bool	sign;
		const int	signGrade;
		const int	execGrade;
	public:
		AForm(void);
		virtual ~AForm(void);
		AForm(const AForm &obj);
		AForm(int signGrade, int execGrade, const std::string &name);
		virtual const AForm	&operator=(const AForm &obj);

		bool	getSigned(void) const;
		int	getSignGrade(void) const;
		int	getExecGrade(void) const;
		std::string	getName(void) const;

		void	beSigned(const Bureaucrat &obj);
		void	execute(const Bureaucrat &obj) const;
		virtual void doAction(void) const = 0;

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

std::ostream	&operator<<(std::ostream &os, const AForm &obj);
