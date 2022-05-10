#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name_) : name(name_) {}

Zombie::~Zombie()
{
	std::cout << name << "'s destructor called" << std::endl;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
