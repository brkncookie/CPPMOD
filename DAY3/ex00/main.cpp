#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Player("Player");
	Player.attack("Enemy");
	Player.takeDamage(10);
	Player.beRepaired(10);
}
