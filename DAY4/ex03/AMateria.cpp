#include "AMateria.hpp"

AMateria::~AMateria(void) {}

AMateria::AMateria(void): type("defacto") {}

AMateria::AMateria(const std::string &type): type(type) {}

AMateria::AMateria(const AMateria &obj)
{
	(void) obj;
}

AMateria &AMateria::operator=(const AMateria &obj)
{
	(void) obj;
	return (*this);
}

const std::string	&AMateria::getType(void) const
{
	return (this->type);
}

void	AMateria::use(ICharacter &target)
{
	(void) target;
}
