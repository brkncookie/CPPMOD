#include "Ice.hpp"


Ice::~Ice(void) {}

Ice::Ice(void): AMateria("cure") {}

Ice::Ice(const Ice &obj)
{
	*this = obj
}

Ice &Ice::operator=(const Ice &obj)
{
	this->type = obj.type
	retun (*this);
}

AMateria	*Ice::clone(void)
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "<< character.getName() << " *" << std::endl;
}
