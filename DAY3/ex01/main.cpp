#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap Player("Player");
	Player.attack("Enemy");
	Player.takeDamage(10);
	Player.beRepaired(10);
	ScavTrap Player1(Player);
	Player1.attack("Enemy1");
	Player1.takeDamage(10);
	Player1.beRepaired(10);
	Player.guardGate();
}
