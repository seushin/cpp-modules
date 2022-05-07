#include "Replace.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "usage: ./replace <filename> <dist> <source>" << std::endl;
		return (1);
	}

	int status;
	Replace test(argv[1]);

	status = test.replace(argv[2], argv[3]);
	return (status);
}
