#include "FragTrap.hpp"

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap's Destructor Called" << std::endl;
}

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "FragTrap's constructor Called" << std::endl;
	this->h_points = 100;
	this->e_points = 50;
	this->attack_damage = 20;
}

FragTrap::FragTrap(std::string	name): ClapTrap(name)
{
	std::cout << "FragTrap's name constructor Called" << std::endl;
	this->h_points = 100;
	this->e_points = 50;
	this->attack_damage = 20;
}

FragTrap::FragTrap(const FragTrap	&obj): ClapTrap(obj)
{
	std::cout << "FragTrap's  copy constructor Called" << std::endl;
	*this = obj;
}

FragTrap	&FragTrap::operator=(const FragTrap	&obj)
{
	std::cout << "FragTrap's copy assignment Called" << std::endl;
	this->name = obj.name;
	this->e_points = obj.e_points;
	this->h_points = obj.h_points;
	this->attack_damage = obj.attack_damage;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Give poor FragTrap a high-five plzzz !" << std::endl;
}

void	FragTrap::attack(const std::string	&target)
{

	if (!(this->e_points) || !(this->h_points))
	{
		std::cout << "Can't Attack " << target << std::endl;
		return;
	}
	this->e_points--;
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}
