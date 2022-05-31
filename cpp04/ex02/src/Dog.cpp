#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal()
{
	*this = other;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	Animal::operator=(rhs);
	brain = new Brain(*rhs.brain);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "mung mung" << std::endl;
}

void Dog::thinkAboutGum()
{
	for (int i = 0; i < MAX_IDEA; ++i)
	{
		brain->setIdea(i, "Gum");
	}
}

std::string Dog::getIdea() const
{
	return (brain->getIdeas()[0]);
}
