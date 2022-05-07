#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
public:
	HumanA(std::string name, Weapon &weapon);
	void attack();

private:
	std::string name_;
	Weapon &weapon_;
};

#endif//HUMANA_HPP
