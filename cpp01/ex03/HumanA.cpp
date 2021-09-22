#include <iostream>
#include <string>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
	: name_(name), weapon_(weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << name_ << " attacks with his " << weapon_.getType() << std::endl;
}
