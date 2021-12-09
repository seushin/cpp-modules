/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:00:42 by seushin           #+#    #+#             */
/*   Updated: 2021/12/06 17:00:42 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
	: name_(name), weapon_(weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << name_ << " attacks with his " << weapon_.getType() << std::endl;
}
