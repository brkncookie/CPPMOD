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
};
