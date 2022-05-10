#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
public:
	Weapon(std::string type_);
	const std::string &getType();
	void setType(std::string type_);

private:
	std::string type;
};

#endif//WEAPON_HPP
