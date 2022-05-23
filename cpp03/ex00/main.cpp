#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap me("me");
	ClapTrap enemy("enemy");

	std::cout << me << std::endl;

	me.attack(enemy.getName());
	std::cout << me << std::endl;

	me.takeDamage(enemy.getAttackDamage());
	std::cout << me << std::endl;

	me.beRepaired(10);
	std::cout << me << std::endl;

	me.takeDamage(20);
	std::cout << me << std::endl;

	me.attack(enemy.getName());
	std::cout << me << std::endl;

	return (0);
}
