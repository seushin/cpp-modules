#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
public:
	Weapon();
	Weapon(std::string type);
	~Weapon();

	const std::string	&getType();
	void	setType(std::string type);

private:
	std::string	type_;
};

#endif // !WEAPON_HPP
