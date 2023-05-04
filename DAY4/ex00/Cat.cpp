#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	this->type = "Cat";
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor Called" << std::endl;
}

Cat::Cat(const Cat	&obj): Animal(obj)
{
	*this = obj;
	std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat	&Cat::operator=(const Cat &obj)
{
	this->type = obj.type;
	std::cout << "Cat Copy Assignment Called" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}
