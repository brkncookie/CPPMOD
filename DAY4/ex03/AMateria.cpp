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
	retun (*this);
}

const std::string	AMateria::getType(void)
{
	return (this->type);
}

void	AMateria::use(ICharacter &target)
{
	(void) target;
}
