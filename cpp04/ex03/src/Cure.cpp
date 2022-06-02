#include "Cure.hpp"
#include "AMateria.hpp"
#include <iostream>

Cure::Cure() : AMateria(CURE_DEFAULT_TYPE)
{
	std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(CURE_DEFAULT_TYPE)
{
	std::cout << "Cure copy constructor" << std::endl;
	*this = other;
}

Cure &Cure::operator=(const Cure &rhs)
{
	AMateria::operator=(rhs);
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor" << std::endl;
}

AMateria *Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
