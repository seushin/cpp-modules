#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain default constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &rhs)
{
	for (int i = 0; i < 100; ++i) {
		ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string const *Brain::getIdeas() const
{
	return (ideas);
}

void Brain::setIdea(int i, std::string idea)
{
	if (i >= MAX_IDEA) {
		return;
	}

	ideas[i] = idea;
}
