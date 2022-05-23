#include "FragTrap.hpp"
#include <iostream>

#define FT_HP 100
#define FT_EP 100
#define FT_AD 30

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	name_ = "FT";
	hitPoint_ = FT_HP;
	energyPoint_ = FT_EP;
	attackDamage_ = FT_AD;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap string constructor called" << std::endl;
	hitPoint_ = FT_HP;
	energyPoint_ = FT_EP;
	attackDamage_ = FT_AD;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap()
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(rhs);
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (energyPoint_ == 0 || hitPoint_ == 0)
	{
		std::cout << "There must be an Hit/Energy point" << std::endl;
		return;
	}
	energyPoint_--;
	std::cout << "HighFives guys" << std::endl;
}
