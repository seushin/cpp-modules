/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:55:38 by seushin           #+#    #+#             */
/*   Updated: 2021/12/06 15:23:14 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

int	main()
{
	int	N = 5;
	std::string	name = "zombie";
	Zombie	*zombies = zombieHorde(N, name);

	for (int i = 0; i < N; ++i)
	{
		zombies[i].announce();
	}
	delete [] zombies;
	return (0);
}
