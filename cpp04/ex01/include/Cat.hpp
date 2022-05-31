#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &rhs);
	~Cat();
	void makeSound() const;
	void thinkAboutChur();
	std::string getIdea() const;

private:
	Brain *brain;
};

#endif//CAT_HPP
