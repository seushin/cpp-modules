#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &rhs);
	~Dog();
	void makeSound() const;
	void thinkAboutGum();
	std::string getIdea() const;

private:
	Brain *brain;
};

#endif//DOG_HPP
