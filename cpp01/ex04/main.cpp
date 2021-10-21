#include "Replace.hpp"
#include <string>

int	main(int argc, char **argv)
{
	int	status;

	if (argc == 4)
	{
		std::string	file = argv[1];
		std::string	src = argv[2];
		std::string	dst = argv[3];
		Replace	target(file);

		status = target.replace(src, dst);
	}
	else
		status = 1;
	return (status);
}
