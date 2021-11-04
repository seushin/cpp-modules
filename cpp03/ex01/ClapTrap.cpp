#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name_("CL4P-TP"),
	hitPoint_(10),
	energyPoint_(10),
	attackDamage_(0)
{
	std::cout << "ClapTrap <" << name_ << "> default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name_(name),
	hitPoint_(10),
	energyPoint_(10),
	attackDamage_(0)
{
	std::cout << "ClapTrap <" << name_ << "> string constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap <" << name_ << "> copy constructor" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	name_ = other.getName();
	hitPoint_ = other.getHitPoint();
	energyPoint_ = other.getEnergyPoint();
	attackDamage_ = other.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap <" << name_ << "> destructor" << std::endl;
}

std::string	ClapTrap::getName() const
{
	return (name_);
}

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

void	ClapTrap::setName(std::string name)
{
	name_ = name;
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
	std::cout
		<< "ClapTrap <" << name_ << "> attacks " << target
		<< ", causing " << attackDamage_ << " points of damage!"
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoint_ < amount)
		hitPoint_ = 0;
	else
	 	hitPoint_ -= amount;
	std::cout
		<< "ClapTrap <" << name_ << "> is damaged " << amount << " points!"
		<< " (hp: " << hitPoint_ << ")"
		<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	hitPoint_ += amount;
	std::cout
		<< "ClapTrap <" << name_ << "> is repaired"
		<< ", causing " << amount << " points of recovery!"
		<< " (hp: " << hitPoint_ << ")"
		<< std::endl;
}

void	ClapTrap::inspect() const
{
	std::cout << "(name: " << name_ << ", HP: " << hitPoint_
		<< ", MP: " << energyPoint_ << ", AD: " << attackDamage_ << ")"
		<< std::endl;
}
