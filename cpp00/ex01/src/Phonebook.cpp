/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:16:47 by seushin           #+#    #+#             */
/*   Updated: 2021/11/27 19:45:39 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include "Phonebook.hpp"

Phonebook::Phonebook() : contact_count(0), column_width(10) {}

void	Phonebook::add(void)
{
	if (contact_count >= MAX_INDEX)
	{
		for (int i = 0; i < MAX_INDEX - 1; ++i)
			contact[i] = contact[i + 1];
		contact_count--;
	}

	Contact	&target = contact[contact_count];

	for (int type = 0; type < target.get_info_size(); ++type)
	{
		std::string	info;

		std::cout << target.get_type_label(type) << "? ";
		std::getline(std::cin, info);
		target.set_info(info, type);
	}
	contact_count++;
}

void	Phonebook::print_divider(void)
{
	for (int i = 0; i < 3; ++i)
		std::cout << std::setfill('-') << std::setw(column_width + 1) << '+';
	std::cout << std::setfill('-') << std::setw(column_width) << "";
	std::cout << std::setfill(' ') << std::endl;
}

void	Phonebook::print_header(void)
{
	print_divider();

	std::cout << std::setw(column_width) << "index";
	for (int type = 0; type <= C_NICKNAME; ++type)
	{
		std::cout << '|'
			<< std::setw(column_width) << Contact::get_type_label(type);
	}
	std::cout << std::endl;

	print_divider();
}

void	Phonebook::print_row(int index)
{
	std::cout << std::setw(column_width) << index;
	for (int type = 0; type <= C_NICKNAME; ++type)
	{
		std::string	column = contact[index].get_info(type);

		if ((int)column.length() > column_width)
		{
			column = column.substr(0, column_width);
			column[column_width - 1] = '.';
		}
		std::cout << '|' << std::setw(column_width) << column;
	}
	std::cout << std::endl;

	print_divider();
}

void	Phonebook::print_contacts_by_table(void)
{
	print_header();
	for (int i = 0; i < contact_count; ++i)
		print_row(i);
}

void	Phonebook::print_contact_info(int index)
{
	print_divider();

	std::cout << "index: " << index << std::endl;
	for (int type = 0; type < contact[index].get_info_size(); ++type)
	{
		std::cout << contact[index].get_type_label(type) << ": "
			<< contact[index].get_info(type) << std::endl;
	}

	print_divider();
}

void	Phonebook::search_contact_by_index(void)
{
	int	index;

	if (contact_count < 1)
		return ;
	std::cout << "search by index > ";
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cout << "Error: not a integer" << std::endl;
	}
	else if (!(0 <= index && index < contact_count))
		std::cout << "Error: out of index" << std::endl;
	else
		print_contact_info(index);
	/* flush buffer */
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void	Phonebook::search(void)
{
	print_contacts_by_table();
	search_contact_by_index();
}
