/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:00:46 by seushin           #+#    #+#             */
/*   Updated: 2021/12/06 17:00:47 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: name_(name), weapon_(NULL) {}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon &weapon)
{
	weapon_ = &weapon;
}

void	HumanB::attack()
{
	if (weapon_ == NULL)
		return ;
	std::cout << name_ << " attacks with his " << weapon_->getType() << std::endl;
}
