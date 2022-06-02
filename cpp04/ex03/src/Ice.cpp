#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria(ICE_DEFAULT_TYPE)
{
	std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(ICE_DEFAULT_TYPE)
{
	std::cout << "Ice copy constructor" << std::endl;
	*this = other;
}

Ice &Ice::operator=(const Ice &rhs)
{
	AMateria::operator=(rhs);
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructor" << std::endl;
}

AMateria *Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "
			  << target.getName() << " *" << std::endl;
}
