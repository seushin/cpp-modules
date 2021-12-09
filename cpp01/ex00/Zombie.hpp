/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:55:20 by seushin           #+#    #+#             */
/*   Updated: 2021/12/06 14:55:21 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void	announce(void);
	void	set_name(std::string name);

private:
	std::string	name_;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif // !ZOMBIE_HPP
