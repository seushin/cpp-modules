/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:16:44 by seushin           #+#    #+#             */
/*   Updated: 2021/11/27 18:20:21 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>
#include "Phonebook.hpp"

std::string	upper_string(std::string &str)
{
	std::locale	loc("en_US.UTF-8");

	for (std::string::size_type i = 0; i < str.length(); ++i)
		str[i] = std::toupper(str[i], loc);
	return (str);
}

int	main(void)
{
	Phonebook	phonebook;
	std::string	cmd;

	while (std::cin.good())
	{
		std::cout << "command > ";
		std::getline(std::cin, cmd);
		cmd = upper_string(cmd);
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
