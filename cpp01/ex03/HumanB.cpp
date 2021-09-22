#include <iostream>
#include <string>
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: name_(name), weapon_(NULL) {}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon &weapon)
{
	weapon_ = &weapon;
}

void	HumanB::attack()
{
	if (weapon_ == NULL)
		return ;
	std::cout << name_ << " attacks with his " << weapon_->getType() << std::endl;
}
