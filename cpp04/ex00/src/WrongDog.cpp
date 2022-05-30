#include "WrongDog.hpp"
#include <iostream>

WrongDog::WrongDog()
{
	std::cout << "WrongDog default constructor called" << std::endl;
	type = "WrongDog";
}

WrongDog::WrongDog(const WrongDog &other)
{
	std::cout << "WrongDog copy constructor called" << std::endl;
	*this = other;
}

WrongDog &WrongDog::operator=(const WrongDog &rhs)
{
	WrongAnimal::operator=(rhs);
	return (*this);
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog destructor called" << std::endl;
}

void WrongDog::makeSound() const
{
	std::cout << "mung mung" << std::endl;
}
