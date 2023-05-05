#pragma once

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria(const std::string	&type);
		AMateria(void);
		AMateria(const AMateria &obj);
		virtual ~AMateria(void);
		virtual	AMateria &operator=(const AMateria &obj);

		const std::string &getType(void) const;
		virtual	AMateria	*clone(void) const = 0 ;
		virtual void use(ICharacter &target);
}
