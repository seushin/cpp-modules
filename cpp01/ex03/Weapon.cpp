#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type) {}

std::string Weapon::getType()
{
	return (type_);
}

void Weapon::setType(std::string type)
{
	type_ = type;
}
