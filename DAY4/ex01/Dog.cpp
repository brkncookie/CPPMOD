#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	this->type = "Dog";
	this->brain = new Brain;
	std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Dog Destructor Called" << std::endl;
}

Dog::Dog(const Dog	&obj): Animal(obj)
{
	*this = obj;
	this->brain = new Brain(*obj.brain);
	std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog	&Dog::operator=(const Dog &obj)
{
	this->type = obj.type;
	*this->brain = *obj.brain;
	std::cout << "Dog Copy Assignment Called" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark Bark" << std::endl;
}
