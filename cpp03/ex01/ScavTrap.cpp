#include "ScavTrap.hpp"
#include <iostream>

#define ST_HP 100
#define ST_EP 50
#define ST_AD 20

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	name_ = "ST";
	hitPoint_ = ST_HP;
	energyPoint_ = ST_EP;
	attackDamage_ = ST_AD;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap string constructor called" << std::endl;
	name_ = name;
	hitPoint_ = ST_HP;
	energyPoint_ = ST_EP;
	attackDamage_ = ST_AD;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(rhs);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (energyPoint_ == 0 || hitPoint_ == 0)
	{
		std::cout << "There must be an Hit/Energy point" << std::endl;
		return;
	}
	energyPoint_--;
	std::cout << "ScavTrap " << name_ << " attacks " << target
			  << ", causing " << attackDamage_ << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (energyPoint_ == 0 || hitPoint_ == 0)
	{
		std::cout << "There must be an Hit/Energy point" << std::endl;
		return;
	}
	energyPoint_--;
	std::cout << name_ << " is now in Gate keeper mode" << std::endl;
}
