/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:15:38 by seushin           #+#    #+#             */
/*   Updated: 2021/11/27 18:16:23 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>
#include <string>

std::string	upper_string(std::string &str)
{
	std::locale	loc("en_US.UTF-8");

	for (std::string::size_type i = 0; i < str.length(); ++i)
		str[i] = std::toupper(str[i], loc);
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string word(argv[i]);

			std::cout << upper_string(word);
		}
		std::cout << std::endl;
	}
	return (0);
}
