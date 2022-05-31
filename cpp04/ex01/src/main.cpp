#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	std::cout << std::string(50, '-') << std::endl;
	{
		const Animal *c = new Cat();
		const Animal *d = new Dog();

		std::cout << c->getType() << std::endl;
		std::cout << d->getType() << std::endl;

		delete c;
		delete d;
	}
	std::cout << std::string(50, '-') << std::endl;
	{
		// test alloc & free Animal array
		const int len = 10;
		Animal **animals = new Animal *[len];

		for (int i = 0; i < len; ++i)
		{
			if (i < len / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		for (int i = 0; i < len; ++i)
		{
			std::cout << animals[i]->getType() << std::endl;
			delete animals[i];
		}
		delete[] animals;
	}
	std::cout << std::string(50, '-') << std::endl;
	{
		// test deep copy
		Cat *c = new Cat();
		Cat *other = new Cat(*c);

		c->thinkAboutChur();
		std::cout << "c: " << c->getIdea() << std::endl;
		std::cout << "other: " << other->getIdea() << std::endl;

		delete c;
		delete other;
	}
	std::cout << std::string(50, '-') << std::endl;

	return (0);
}
