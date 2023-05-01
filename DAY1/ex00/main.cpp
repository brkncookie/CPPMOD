#include "Zombie.hpp"

int main(void)
{
	Zombie *zom = newZombie("Nor");
	zom->announce();
	delete zom;

	randomChump("brkncookie");
	return (0);
}
