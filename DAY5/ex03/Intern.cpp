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
	ptr2method	p2m[3] = {&Intern::createRRF, &Intern::createPPF, &Intern::createSCF};
	std::string forms[3] = {"robotomy request", "presidential request", "shrubbery request"};
	int inx = -1;

	while (++inx < 3)
		if (formname == forms[inx])
			return ((this->*p2m[inx])(target));
	return (NULL);
}

AForm	*Intern::createPPF(const std::string	&target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::createSCF(const std::string	&target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createRRF(const std::string	&target)
{
	return (new RobotomyRequestForm(target));
}
