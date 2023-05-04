#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string	name;
		int		h_points;
		int		e_points;
		int		attack_damage;
	public:
		ClapTrap(void);
		~ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const	ClapTrap	&obj);
		ClapTrap	&operator=(const	ClapTrap	&obj);
		void		attack(const std::string	&target);
		void		takeDamage(unsigned int	amount);
		void		beRepaired(unsigned int amount);
};
