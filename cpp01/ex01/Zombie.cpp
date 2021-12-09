/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:55:08 by seushin           #+#    #+#             */
/*   Updated: 2021/12/06 14:55:09 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie() : name_("no_name") {}

Zombie::Zombie(std::string name) : name_(name) {}

Zombie::~Zombie()
{
	std::cout << "Destroyed " << name_ << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	name_ = name;
}
