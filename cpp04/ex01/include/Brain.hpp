#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &rhs);
	~Brain();

private:
	std::string ideas[100];
};

#endif// !BRAIN_HPP
