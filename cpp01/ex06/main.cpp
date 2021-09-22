#include <iostream>
#include <string>
#include "Karen.hpp"

int	main(int argc, char **argv)
{
	Karen	karen;

	if (argc == 2)
	{
		bool	on = false;
		std::string	levels[4] = {
			"DEBUG",
			"INFO",
			"WARNING",
			"ERROR"
		};

		for (int i = 0; i < 4; ++i)
		{
			if (on || levels[i] == argv[1])
			{
				karen.complain(levels[i]);
				std::cout << std::endl;
				on = true;
			}
		}
		if (not on)
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
