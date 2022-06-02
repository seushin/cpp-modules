#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria() : type_("")
{
	std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(const std::string &type) : type_(type)
{
	std::cout << "AMateria string constructor" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "AMateria copy constructor" << std::endl;
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	type_ = rhs.type_;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor" << std::endl;
}

const std::string &AMateria::getType() const
{
	return (type_);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* " << target.getName() << " *" << std::endl;
}
