#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern Constructor Called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
	*this = obj;
	std::cout << "Intern Copy Constructor Called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern Destructor Called" << std::endl;
}

Intern &Intern::operator=(const Intern &obj)
{
	(void) obj;
	std::cout << "Intern Copy Assignment Operator Called" << std::endl;
	return (*this);
}


AForm *Intern::makeForm(const std::string &formname, const std::string &target)
{
	std::string forms[3] = {"robotomy request", "presidential request", "shrubbery request"};
	int inx = -1;

	while (inx < 3)
		if (forms[++inx] == formname)
			break;
	switch (inx)
	{
		case 0:
			return (new RobotomyRequestForm(target));
		case 1:
			return (new PresidentialPardonForm(target));
		case 2:
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << "Unknown Form" << std::endl;
			break;
	}
	return (NULL);
}
