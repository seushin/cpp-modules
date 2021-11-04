#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap <" << getName()
		<< "> default constructor" << std::endl;
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap <" << getName()
		<< "> string constructor" << std::endl;
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap <" << getName()
		<< "> copy constructor" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap <" << getName() << "> destructor" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap::";
	ClapTrap::attack(target);
}

void	FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FragTrap::";
	ClapTrap::beRepaired(amount);
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap::";
	ClapTrap::takeDamage(amount);
}

void	FragTrap::highFiveGuys()
{
	std::cout << "FragTrap <" << getName() << "> highFive!" << std::endl;
}
