#include "Convert.hpp"
#include <exception>
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	try
	{
		Convert convert(argv[1]);

		std::cout << convert << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
