#include "ScavTrap.hpp"

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap's Destructor Called" << std::endl;
}

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "ScavTrap's constructor Called" << std::endl;
	this->h_points = 100;
	this->e_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string	name): ClapTrap(name)
{
	std::cout << "ScavTrap's name constructor Called" << std::endl;
	this->h_points = 100;
	this->e_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap	&obj): ClapTrap(obj)
{
	std::cout << "ScavTrap's  copy constructor Called" << std::endl;
	*this = obj;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap	&obj)
{
	std::cout << "ScavTrap's copy assignment Called" << std::endl;
	this->name = obj.name;
	this->e_points = obj.e_points;
	this->h_points = obj.h_points;
	this->attack_damage = obj.attack_damage;
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "Gate-Keeper mode successfully activated" << std::endl;
}

void	ScavTrap::attack(const std::string	&target)
{

	if (!(this->e_points) || !(this->h_points))
	{
		std::cout << "Can't Attack " << target << std::endl;
		return;
	}
	this->e_points--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}
