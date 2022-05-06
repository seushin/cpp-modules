#include "Zombie.hpp"

int main()
{
	{
		Zombie zombie("foo");

		zombie.announce();
	}
	{
		Zombie *zombie = newZombie("bar");

		zombie->announce();
		delete zombie;
	}
	{
		randomChump("buz");
	}
	return (0);
}
