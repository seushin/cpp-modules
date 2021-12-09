/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:55:51 by seushin           #+#    #+#             */
/*   Updated: 2021/12/06 15:31:46 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << ">> create string, pointer, referer" << std::endl;
	std::cout << "std::string	str = \"HI THIS IS BRAIN\";" << std::endl;
	std::cout << "std::string	*stringPTR = &str;" << std::endl;
	std::cout << "std::string	&stringREF = str;" << std::endl;

	std::cout << std::endl;

	std::cout << ">> print memory address" << std::endl;
	std::cout << "&str :\t\t" << &str << std::endl;
	std::cout << "stringPTR :\t" << stringPTR << std::endl;
	std::cout << "&stringREF :\t" << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << ">> print string" << std::endl;
	std::cout << "str :\t\t" << str << std::endl;
	std::cout << "*stringPTR :\t" << *stringPTR << std::endl;
	std::cout << "stringREF :\t" << stringREF << std::endl;

	return (0);
}
