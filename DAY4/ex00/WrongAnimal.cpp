#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("WrongAnimal")
{
	std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal	&obj): type(obj.type)
{
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &obj)
{
	this->type = obj.type;
	std::cout << "WrongAnimal Copy Assignment Called" << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "*void sound*" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}
