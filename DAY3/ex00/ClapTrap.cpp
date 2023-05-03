#include "ClapTrap.hpp"

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap's Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(void): h_points(10), e_points(10), attack_damage(0)
{
	std::cout << "ClapTrap's constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string	name): name(name), h_points(10), e_points(10), attack_damage(0)
{
	std::cout << "ClapTrap's name constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap	&obj): h_points(10), e_points(10), attack_damage(0)
{
	*this = obj;
	std::cout << "ClapTrap's copy constructor Called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap	&obj)
{
	std::cout << "ClapTrap's copy assignment Called" << std::endl;
	this->name = obj.name;
	this->e_points = obj.e_points;
	this->h_points = obj.h_points;
	this->attack_damage = obj.attack_damage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (!(this->e_points) || !(this->h_points))
	{
		std::cout << "Can't Attack " << target << std::endl;
		return;
	}
	this->e_points--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}


void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " took " << amount << " amout of damage" << std::endl;
	this->h_points -= amount < (unsigned int)this->h_points? amount : this->h_points;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!(this->e_points))
		std::cout << "ClapTrap " << this->name << " can't procced to repair itself" << std::endl;

	std::cout << "ClapTrap " << this->name << " repaired itself and added " << amount << " amount of hits points " << std::endl;
	this->e_points--;
	this->h_points += amount;

}
