/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:00:54 by seushin           #+#    #+#             */
/*   Updated: 2021/12/06 17:00:55 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	type_ = type;
}

Weapon::~Weapon() {}

const std::string	&Weapon::getType()
{
	const std::string	&res = type_;
	return (res);
}

void	Weapon::setType(std::string type)
{
	type_ = type;
}
