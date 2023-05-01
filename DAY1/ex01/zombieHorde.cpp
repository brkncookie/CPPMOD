#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	int inx = 0;
	Zombie *zom = new Zombie[N];

	while(inx < N)
		zom[inx++].Nameset(name);
	return (zom);
}
