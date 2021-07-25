#include <iostream>
#include <locale>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string	str = argv[i];
			std::locale	loc("en_US.UTF-8");

			for (std::string::size_type j = 0; j < str.length(); ++j)
				std::cout << std::toupper(str[j], loc);
		} 
		std::cout << std::endl;
	}
	return (0);
}
