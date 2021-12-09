/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:00:55 by seushin           #+#    #+#             */
/*   Updated: 2021/12/06 17:00:56 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
public:
	Weapon(std::string type);
	~Weapon();

	const std::string	&getType();
	void	setType(std::string type);

private:
	std::string	type_;
};

#endif // !WEAPON_HPP
