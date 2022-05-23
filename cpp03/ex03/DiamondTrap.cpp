#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
	: ClapTrap("DT_clap_name"), FragTrap(), ScavTrap(), name_("DT")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	hitPoint_ = FT_HP;
	energyPoint_ = ST_EP;
	attackDamage_ = FT_AD;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), name_(name)
{
	std::cout << "DiamondTrap string constructor called" << std::endl;
	hitPoint_ = FT_HP;
	energyPoint_ = ST_EP;
	attackDamage_ = FT_AD;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	ClapTrap::operator=(rhs);
	name_ = rhs.name_;

	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I'm " << name_
			  << " and Clap name is " << ClapTrap::name_ << std::endl;
}
