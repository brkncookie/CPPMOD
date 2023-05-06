#include "Ice.hpp"


Ice::~Ice(void) {}

Ice::Ice(void): AMateria("cure") {}

Ice::Ice(const Ice &obj): AMateria(obj)
{
	*this = obj;
}

Ice &Ice::operator=(const Ice &obj)
{
	this->type = obj.type;
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl;
}
