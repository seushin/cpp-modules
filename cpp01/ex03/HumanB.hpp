#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
public:
	HumanB(std::string name);
	void setWeapon(Weapon &weapon);
	void attack();

private:
	std::string name_;
	Weapon *weapon_;
};

#endif//HUMANB_HPP
