/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:16:40 by seushin           #+#    #+#             */
/*   Updated: 2021/11/28 00:19:20 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact()
{
	for (int i = 0; i < C_SIZE; ++i)
		info[i] = "";
}

void	Contact::set_info(std::string str, int type)
{
	info[type] = str;
}

std::string	Contact::get_info(int type)
{
	return (info[type]);
}

int	Contact::get_info_size(void)
{
	return (C_SIZE);
}

std::string	Contact::get_type_label(int type)
{
	if (type == C_FIRST_NAME)
		return ("first name");
	else if (type == C_LAST_NAME)
		return ("last name");
	else if (type == C_NICKNAME)
		return ("nickname");
	else if (type == C_PHONE_NUMBER)
		return ("phone number");
	else if (type == C_SECRET)
		return ("darkest secret");
	else
		return ("undefined type!");
}
