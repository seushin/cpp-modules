#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name_(name) {}

void Zombie::announce()
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
