#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z1;
	Zombie	z2;

	z1 = newZombie("z1");
	z2.set_name("z2");
	randomChump("z3");

	z1->announce();
	z2.announce();

	delete z1;
	return (0);
}
