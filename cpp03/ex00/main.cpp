#include "ClapTrap.hpp"
#include <cassert>
#include <iostream>

int main()
{
	ClapTrap me("me");
	ClapTrap enemy("enemy");

	assert(me.getHitPoint() == 10);
	assert(me.getEnergyPoint() == 10);
	assert(me.getAttackDamage() == 0);
	std::cout << me << std::endl;

	me.attack(enemy.getName());
	assert(me.getEnergyPoint() == 9);
	std::cout << me << std::endl;

	me.takeDamage(enemy.getAttackDamage());
	assert(me.getHitPoint() == 10);
	std::cout << me << std::endl;

	me.beRepaired(10);
	assert(me.getHitPoint() == 20);
	assert(me.getEnergyPoint() == 8);
	std::cout << me << std::endl;

	me.takeDamage(20);
	assert(me.getHitPoint() == 0);
	std::cout << me << std::endl;

	me.attack(enemy.getName());
	assert(me.getEnergyPoint() == 8);
	std::cout << me << std::endl;

	return (0);
}
