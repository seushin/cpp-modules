/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:55:47 by seushin           #+#    #+#             */
/*   Updated: 2021/12/06 15:21:59 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

static std::string	to_string(int i)
{
	if (i == 0)
		return (std::string("0"));

	std::string	res;

	for (int mod = i % 10; i != 0; i /= 10, mod = i % 10)
	{
		res.insert(0, 1, static_cast<char>('0' + mod));
	}
	return (res);
}

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombies = new Zombie[N];

	for (int i = 0; i < N; ++i)
	{
		zombies[i].set_name(name + to_string(i));
	}
	return (zombies);
}
