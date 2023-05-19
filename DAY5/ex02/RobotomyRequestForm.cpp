#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm(72, 45, "RobotomyRequestForm"), target("defacto")
{
	std::cout << "RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string &target): AForm(72, 45, "RobotomyRequestForm"), target(target)
{
	std::cout << "RobotomyRequestForm Target Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj): AForm(obj), target(obj.target)
{
	std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	this->target = obj.target;
	std::cout << "RobotomyRequestForm Copy Assignment Operator Called" << std::endl;
	return (*this);
}


void	RobotomyRequestForm::doAction(void) const
{
	std::srand(std::time(0));
	int rand_int = std::rand();
	if (rand_int % 2)
	{
		std::cout << "drilling noises" << std::endl;
		std::cout << "drilling noises" << std::endl;
		std::cout << "drilling noise" << std::endl;
		std::cout << this->target << " has been robotomized successfully 50% of the time" << std::endl;
	}
	else
	{
		std::cout << "drilling noises" << std::endl;
		std::cout << "drilling noises" << std::endl;
		std::cout << this->target << " robotomy failed" << std::endl;
	}
}
