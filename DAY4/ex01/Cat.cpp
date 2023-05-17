#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	std::cout << "Cat Default Constructor Called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor Called" << std::endl;
	delete this->brain;
}

Cat::Cat(const Cat	&obj): Animal(obj)
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
	this->brain = new Brain;
	*this = obj;
}

Cat	&Cat::operator=(const Cat &obj)
{
	std::cout << "Cat Copy Assignment Called" << std::endl;
	this->type = obj.type;
	*this->brain = *obj.brain;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}
