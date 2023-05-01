#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL) {}
HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with their " << (weapon != NULL ? weapon->getType(): "NULL") << std::endl;
}
