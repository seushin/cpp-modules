#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "ScavTrap <" << getName()
		<< "> default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "ScavTrap <" << getName()
		<< "> string constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap <" << getName()
		<< "> copy constructor" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap <" << getName() << "> destructor" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap::";
	ClapTrap::attack(target);
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap::";
	ClapTrap::beRepaired(amount);
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap::";
	ClapTrap::takeDamage(amount);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap <" << getName()
		<< "> is enterred in gate keeper mode" << std::endl;
}
