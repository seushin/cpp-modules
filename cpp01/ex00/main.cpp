/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:55:05 by seushin           #+#    #+#             */
/*   Updated: 2021/12/06 14:55:07 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z1 = newZombie("z1");
	Zombie	z2("z2");
	randomChump("z3");

	z1->announce();
	z2.announce();

	delete z1;
	return (0);
}
