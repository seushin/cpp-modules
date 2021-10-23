#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name_("anonymous"),
	hitPoint_(10),
	energyPoint_(10),
	attackDamage_(0)
{
	std::cout << "대사" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name_(name),
	hitPoint_(10),
	energyPoint_(10),
	attackDamage_(0)
{
	std::cout << "대사" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	hitPoint_ = other.getHitPoint();
	energyPoint_ = other.getEnergyPoint();
	attackDamage_ = other.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap() {}

unsigned int	ClapTrap::getHitPoint() const
{
	return (hitPoint_);
}

unsigned int	ClapTrap::getEnergyPoint() const
{
	return (energyPoint_);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (attackDamage_);
}

void	ClapTrap::setHitPoint(unsigned int hitPoint)
{
	hitPoint_ = hitPoint;
}

void	ClapTrap::setEnergyPoint(unsigned int energyPoint)
{
	energyPoint_ = energyPoint;
}

void	ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	attackDamage_ = attackDamage;
}

void	ClapTrap::attack(const std::string &target)
{
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	energyPoint_ -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	
}
