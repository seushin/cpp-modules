#include "ClapTrap.hpp"
#include <iostream>

#define CT_HP 10
#define CT_EP 10
#define CT_AD 0

ClapTrap::ClapTrap()
	: name_("CT"), hitPoint_(CT_HP), energyPoint_(CT_EP), attackDamage_(CT_AD)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name_(name), hitPoint_(CT_HP), energyPoint_(CT_EP), attackDamage_(CT_AD)
{
	std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	name_ = rhs.name_;
	hitPoint_ = rhs.hitPoint_;
	energyPoint_ = rhs.energyPoint_;
	attackDamage_ = rhs.attackDamage_;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const ClapTrap &rhs)
{
	o << rhs.getName()
	  << ": hp(" << rhs.getHitPoint()
	  << "), ep(" << rhs.getEnergyPoint()
	  << "), ad(" << rhs.getAttackDamage() << ")";
	return (o);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (energyPoint_ == 0 || hitPoint_ == 0)
	{
		std::cout << "There must be an Hit/Energy point" << std::endl;
		return;
	}
	energyPoint_--;
	std::cout << "ClapTrap " << name_ << " attacks " << target
			  << ", causing " << attackDamage_ << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoint_ == 0 || hitPoint_ == 0)
	{
		std::cout << "There must be an Hit/Energy point" << std::endl;
		return;
	}
	energyPoint_--;
	hitPoint_ += amount;
	std::cout << "ClapTrap " << name_ << " repaired "
			  << amount << " points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (energyPoint_ == 0 || hitPoint_ == 0)
	{
		std::cout << "There must be an Hit/Energy point" << std::endl;
		return;
	}
	if (hitPoint_ < amount)
		hitPoint_ = 0;
	else
		hitPoint_ -= amount;
	std::cout << "ClapTrap " << name_ << " take "
			  << amount << " points of damage!" << std::endl;
}

std::string ClapTrap::getName() const
{
	return (name_);
}

unsigned int ClapTrap::getHitPoint() const
{
	return (hitPoint_);
}

unsigned int ClapTrap::getEnergyPoint() const
{
	return (energyPoint_);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (attackDamage_);
}
