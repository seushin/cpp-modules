#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &other) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
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
