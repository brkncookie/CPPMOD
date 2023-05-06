#pragma once

#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure(const std::string	&type);
		Cure(void);
		Cure(const Cure &obj);
		~Cure(void);
		Cure &operator=(const Cure &obj);

		const std::string &getType(void) const;
		AMateria	*clone(void) const;
		void use(ICharacter &target);
};
