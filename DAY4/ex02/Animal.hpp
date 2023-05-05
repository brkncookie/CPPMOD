#pragma once

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(const Animal	&obj);
		virtual Animal &operator=(const Animal &obj);
		virtual	~Animal(void);
		virtual void makeSound(void) const = 0;
		std::string	getType(void) const;
};
