#pragma once

#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice(const std::string	&type);
		Ice(void);
		Ice(const Ice &obj);
		~Ice(void);
		Ice &operator=(const Ice &obj);

		const std::string &getType(void) const;
		Ice	*clone(void) const;
		void use(ICharacter &target);
}
