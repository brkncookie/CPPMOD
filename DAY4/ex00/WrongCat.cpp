#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor Called" << std::endl;
}

WrongCat::WrongCat(const WrongCat	&obj): WrongAnimal(obj)
{
	*this = obj;
	std::cout << "WrongCat Copy Constructor Called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &obj)
{
	this->type = obj.type;
	std::cout << "WrongCat Copy Assignment Called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}
