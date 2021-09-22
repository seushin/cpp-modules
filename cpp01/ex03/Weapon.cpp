#include <string>
#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type)
{
	type_ = type;
}

Weapon::~Weapon() {}

const std::string	&Weapon::getType()
{
	const std::string	&res = type_;
	return (res);
}

void	Weapon::setType(std::string type)
{
	type_ = type;
}
