#pragma once

#include <iostream>
#include "Form.hpp"

class Form;
class Bureaucrat
{
	private:
		const std::string	name;
		int			grade;
	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		const Bureaucrat	&operator=(const Bureaucrat &obj);

		int	getGrade(void) const;
		std::string	getName(void) const;
		void	incGrade(void);
		void	decGrade(void);
		void	signForm(const Form	&obj) const;

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);
