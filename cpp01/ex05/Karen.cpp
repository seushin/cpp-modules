/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:51:10 by seushin           #+#    #+#             */
/*   Updated: 2021/12/09 17:59:23 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Karen.hpp"

Karen::Karen() {}

Karen::~Karen() {}

void	Karen::complain(std::string level)
{
	std::string	levelList[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	karenFuncPtr funcList[4] = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};

	for (int i = 0; i < 4; ++i)
	{
		if (levelList[i] == level)
		{
			(this->*funcList[i])();
			break ;
		}
	}
}

void	Karen::debug()
{
	std::cout << "[ DEBUG ]" << std::endl
		<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl
		<< "I just love it!" << std::endl;
}

void	Karen::info()
{
	std::cout << "[ INFO ]" << std::endl
		<< "I cannot believe adding extra bacon cost more money." << std::endl
		<< "You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning()
{
	std::cout << "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free." << std::endl
		<< "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error()
{
	std::cout << "[ ERROR ]" << std::endl
		<< "This is unacceptable, I want to speak to the manager now." << std::endl;
}
