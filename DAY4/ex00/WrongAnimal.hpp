#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal	&obj);
		WrongAnimal &operator=(const WrongAnimal &obj);
		~WrongAnimal(void);
		void makeSound(void) const;
		std::string	getType(void) const;
};
