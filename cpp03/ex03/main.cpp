#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
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

		me.attack(enemy.getName());
		assert(me.getEnergyPoint() == 99);

		me.takeDamage(enemy.getAttackDamage());
		assert(me.getHitPoint() == 70);

		me.beRepaired(10);
		assert(me.getHitPoint() == 80);
		assert(me.getEnergyPoint() == 98);

		me.highFivesGuys();
		assert(me.getEnergyPoint() == 97);

		me.takeDamage(200);
		assert(me.getHitPoint() == 0);

		me.attack(enemy.getName());
		assert(me.getEnergyPoint() == 97);
	}
	std::cout << std::string(80, '-') << std::endl;
	{
		DiamondTrap a;
		std::cout << std::endl;

		DiamondTrap b("b");
		std::cout << std::endl;

		DiamondTrap c(b);
		std::cout << std::endl;

		a = c;
		std::cout << std::endl;

		a.whoAmI();
		std::cout << a << std::endl;
		b.whoAmI();
		std::cout << b << std::endl;
		c.whoAmI();
		std::cout << c << std::endl;
	}
	std::cout << std::string(80, '-') << std::endl;
	{
		DiamondTrap me("me");
		DiamondTrap enemy("enemy");

		assert(me.getHitPoint() == 100);
		assert(me.getEnergyPoint() == 50);
		assert(me.getAttackDamage() == 30);
		std::cout << me << std::endl;

		me.attack(enemy.getName());
		assert(me.getEnergyPoint() == 49);
		std::cout << me << std::endl;

		me.takeDamage(enemy.getAttackDamage());
		assert(me.getHitPoint() == 70);
		assert(me.getEnergyPoint() == 49);
		std::cout << me << std::endl;

		me.beRepaired(10);
		assert(me.getHitPoint() == 80);
		assert(me.getEnergyPoint() == 48);
		std::cout << me << std::endl;

		me.whoAmI();

		me.takeDamage(200);
		assert(me.getHitPoint() == 0);
		assert(me.getEnergyPoint() == 48);
		std::cout << me << std::endl;

		me.attack(enemy.getName());
		assert(me.getEnergyPoint() == 48);
		std::cout << me << std::endl;
	}

	return (0);
}
