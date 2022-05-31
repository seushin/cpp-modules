#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define MAX_IDEA 100

class Brain
{
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &rhs);
	~Brain();
	std::string const *getIdeas() const;
	void setIdea(int i, std::string idea);

private:
	std::string ideas[MAX_IDEA];
};

#endif// !BRAIN_HPP
