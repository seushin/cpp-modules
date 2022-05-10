#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("anyone") {}

Zombie::Zombie(std::string name_) : name(name_) {}

Zombie::~Zombie()
{
	std::cout << name << "'s destructor called" << std::endl;
}

void Zombie::setName(std::string name_)
{
	name = name_;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
