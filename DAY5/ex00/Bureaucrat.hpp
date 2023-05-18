#pragma once

#include <iostream>

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
