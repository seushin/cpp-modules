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

Zombie	*zombieHorde(int N, std::string name);

#endif // !ZOMBIE_HPP
