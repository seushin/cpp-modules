#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &other)
{
	*this = other;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	Animal::operator=(rhs);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "mung mung" << std::endl;
}
