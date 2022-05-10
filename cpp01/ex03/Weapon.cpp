#include "Weapon.hpp"

Weapon::Weapon(std::string type_) : type(type_) {}

const std::string &Weapon::getType()
{
	return (type);
}

void Weapon::setType(std::string type_)
{
	type = type_;
}
