#pragma once

#include <iostream>

class Zombie
{
	public:
		Zombie(std::string name);
		Zombie();
		~Zombie();
		void	announce(void);
		void	Nameset(std::string name);
	private:
		std::string name;
};

Zombie *zombieHorde(int N, std::string name);
