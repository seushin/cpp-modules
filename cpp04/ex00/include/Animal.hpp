#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &rhs);
	~Animal();
	std::string getType() const;
	virtual void makeSound() const;

protected:
	std::string type;
};

#endif//ANIMAL_HPP