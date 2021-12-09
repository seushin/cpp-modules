/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:00:48 by seushin           #+#    #+#             */
/*   Updated: 2021/12/06 17:00:49 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	~HumanB();

	void	attack();
	void	setWeapon(Weapon &weapon);

private:
	std::string	name_;
	Weapon	*weapon_;
};

#endif // !HUMANB_HPP
