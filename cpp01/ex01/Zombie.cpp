#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie()
{
	name_ = "no_name";
}

Zombie::~Zombie()
{
	std::cout << "Destroyed " << name_ << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	name_ = name;
}
