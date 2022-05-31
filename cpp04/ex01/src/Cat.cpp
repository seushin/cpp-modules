#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal()
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

void Cat::thinkAboutChur()
{
	for (int i = 0; i < MAX_IDEA; ++i)
	{
		brain->setIdea(i, "CHUR");
	}
}

std::string Cat::getIdea() const
{
	return (brain->getIdeas()[0]);
}
