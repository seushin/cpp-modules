#include <iostream>
#include <string>
#include "Zombie.hpp"

int	main()
{
	int	N = 5;
	std::string	name = "zombie";
	Zombie	*zombies = zombieHorde(N, name);

	for (int i = 0; i < N; ++i)
	{
		zombies[i].announce();
	}
	delete [] zombies;
	return (0);
}
