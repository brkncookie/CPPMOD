#include "Animal.hpp"

Animal::Animal(void): type("Animal")
{
	std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor Called" << std::endl;
}

Animal::Animal(const Animal	&obj): type(obj.type)
{
	std::cout << "Animal Copy Constructor Called" << std::endl;
}

Animal	&Animal::operator=(const Animal &obj)
{
	this->type = obj.type;
	std::cout << "Animal Copy Assignment Called" << std::endl;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "*void sound*" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}
