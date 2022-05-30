#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &rhs)
{
	Animal::operator=(rhs);
	brain = new Brain(*rhs.brain);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}
