#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain Default Constructor Called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor Called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain Copy Constructor Called" << std::endl;
	*this = obj;
}

const Brain	&Brain::operator=(const Brain &obj)
{
	for(int inx = 0; inx < 100; inx++)
		this->ideas[inx] = obj.ideas[inx];
	std::cout << "Brain Copy Assignment Operator Called" << std::endl;
	return (*this);
}
