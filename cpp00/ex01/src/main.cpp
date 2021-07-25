#include <iostream>
#include <locale>
#include "Phonebook.hpp"

void	upper_string(std::string &str)
{
	std::locale	loc("en_US.UTF-8");

	for (std::string::size_type i = 0; i < str.length(); ++i)
		str[i] = std::toupper(str[i], loc);
}

int	main(void)
{
	Phonebook	phonebook;
	std::string	cmd;

	while (std::cin.good())
	{
		std::cout << "command > ";
		std::getline(std::cin, cmd);
		upper_string(cmd);
		if (std::cin.eof() || cmd == "EXIT")
			break ;
		else if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		else
			std::cout << "\e[33mUsage: ADD | SEARCH | EXIT\e[0m" << std::endl;
	}
	return (0);
}
