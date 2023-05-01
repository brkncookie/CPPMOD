#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::Zombie(std::string name): name(name) {}

Zombie::~Zombie()
{
	std::cout << this->name << " will meet their creator" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::Nameset(std::string name)
{
	this->name = name;
}
