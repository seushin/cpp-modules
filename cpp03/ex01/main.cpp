#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <cassert>
#include <string>
#include <iostream>

int main()
{
	{
		ClapTrap me("me");
		ClapTrap enemy("enemy");

		assert(me.getHitPoint() == 10);
		assert(me.getEnergyPoint() == 10);
		assert(me.getAttackDamage() == 0);

		me.attack(enemy.getName());
		assert(me.getEnergyPoint() == 9);

		me.takeDamage(enemy.getAttackDamage());
		assert(me.getHitPoint() == 10);

		me.beRepaired(10);
		assert(me.getHitPoint() == 20);
		assert(me.getEnergyPoint() == 8);

		me.takeDamage(20);
		assert(me.getHitPoint() == 0);

		me.attack(enemy.getName());
		assert(me.getEnergyPoint() == 8);
	}
	std::cout << std::string(80, '-') << std::endl;
	{
		ScavTrap me("me");
		ScavTrap enemy("enemy");

		assert(me.getHitPoint() == 100);
		assert(me.getEnergyPoint() == 50);
		assert(me.getAttackDamage() == 20);
		std::cout << me << std::endl;

		me.attack(enemy.getName());
		assert(me.getEnergyPoint() == 49);
		std::cout << me << std::endl;

		me.takeDamage(enemy.getAttackDamage());
		assert(me.getHitPoint() == 80);
		std::cout << me << std::endl;

		me.beRepaired(10);
		assert(me.getHitPoint() == 90);
		assert(me.getEnergyPoint() == 48);
		std::cout << me << std::endl;

		me.guardGate();
		assert(me.getEnergyPoint() == 47);

		me.takeDamage(200);
		assert(me.getHitPoint() == 0);
		std::cout << me << std::endl;

		me.attack(enemy.getName());
		assert(me.getEnergyPoint() == 47);
		std::cout << me << std::endl;
	}

	return (0);
}
