/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:16:40 by seushin           #+#    #+#             */
/*   Updated: 2021/12/03 14:08:24 by seushin          ###   ########.fr       */
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

std::string	Contact::get_type_label(int type)
{
	if (type == C_FIRST_NAME)
		return ("First name");
	else if (type == C_LAST_NAME)
		return ("Last name");
	else if (type == C_NICKNAME)
		return ("Nickname");
	else if (type == C_PHONE_NUMBER)
		return ("Phone number");
	else if (type == C_SECRET)
		return ("Darkest secret");
	else
		return ("Undefined type!");
}
