#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern &obj);
		Intern &operator=(const Intern &obj);
		AForm *makeForm(const std::string &formname, const std::string &target);
		AForm	*createPPF(const std::string &target);
		AForm	*createSCF(const std::string &target);
		AForm	*createRRF(const std::string &target);
};

typedef	AForm	*(Intern::*ptr2method)(const std::string	&);

