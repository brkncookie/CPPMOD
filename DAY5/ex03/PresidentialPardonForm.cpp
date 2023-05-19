#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm(25, 5, "PresidentialPardonForm"), target("defacto")
{
	std::cout << "PresidentialPardonForm Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm(25, 5, "PresidentialPardonForm"), target(target)
{
	std::cout << "PresidentialPardonForm Target Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj): AForm(obj), target(obj.target)
{
	std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm Destructor Called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	this->target = obj.target;
	std::cout << "PresidentialPardonForm Copy Assignment Operator Called" << std::endl;
	return (*this);
}


void	PresidentialPardonForm::doAction(void) const
{
        std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
