#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	this->type = "Cat";
	this->brain = new Brain;
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Cat Destructor Called" << std::endl;
}

Cat::Cat(const Cat	&obj): Animal(obj)
{
	*this = obj;
	this->brain = new Brain(*obj.brain);
	std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat	&Cat::operator=(const Cat &obj)
{
	this->type = obj.type;
	*this->brain = *obj.brain;
	std::cout << "Cat Copy Assignment Called" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}
