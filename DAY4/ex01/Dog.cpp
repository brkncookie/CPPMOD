#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	std::cout << "Dog Default Constructor Called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor Called" << std::endl;
	delete this->brain;
}

Dog::Dog(const Dog	&obj): Animal(obj)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
	this->brain = new Brain;
	*this = obj;
}

Dog	&Dog::operator=(const Dog &obj)
{
	std::cout << "Dog Copy Assignment Called" << std::endl;
	this->type = obj.type;
	*this->brain = *obj.brain;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark Bark" << std::endl;
}
