#include "Cure.hpp"


Cure::~Cure(void) {}

Cure::Cure(void): AMateria("cure") {}

Cure::Cure(const Cure &obj)
{
	*this = obj
}

Cure &Cure::operator=(const Cure &obj)
{
	this->type = obj.type
	retun (*this);
}

AMateria	*Cure::clone(void)
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
