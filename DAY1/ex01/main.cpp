#include "Zombie.hpp"

int main(void)
{
	Zombie *zom = zombieHorde(10, "Nor");

	for(int i = 0; i < 10; i++)
		zom[i].announce();
	delete[] zom;

	return (0);
}
