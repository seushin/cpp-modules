#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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

		me.attack(enemy.getName());
		assert(me.getEnergyPoint() == 49);

		me.takeDamage(enemy.getAttackDamage());
		assert(me.getHitPoint() == 80);

		me.beRepaired(10);
		assert(me.getHitPoint() == 90);
		assert(me.getEnergyPoint() == 48);

		me.guardGate();
		assert(me.getEnergyPoint() == 47);

		me.takeDamage(200);
		assert(me.getHitPoint() == 0);

		me.attack(enemy.getName());
		assert(me.getEnergyPoint() == 47);
	}
	std::cout << std::string(80, '-') << std::endl;
	{
		FragTrap me("me");
		FragTrap enemy("enemy");

		assert(me.getHitPoint() == 100);
		assert(me.getEnergyPoint() == 100);
		assert(me.getAttackDamage() == 30);
		std::cout << me << std::endl;

		me.attack(enemy.getName());
		assert(me.getEnergyPoint() == 99);
		std::cout << me << std::endl;

		me.takeDamage(enemy.getAttackDamage());
		assert(me.getHitPoint() == 70);
		assert(me.getEnergyPoint() == 99);
		std::cout << me << std::endl;

		me.beRepaired(10);
		assert(me.getHitPoint() == 80);
		assert(me.getEnergyPoint() == 98);
		std::cout << me << std::endl;

		me.highFivesGuys();
		assert(me.getEnergyPoint() == 97);

		me.takeDamage(200);
		assert(me.getHitPoint() == 0);
		assert(me.getEnergyPoint() == 97);
		std::cout << me << std::endl;

		me.attack(enemy.getName());
		assert(me.getEnergyPoint() == 97);
		std::cout << me << std::endl;
	}

	return (0);
}
