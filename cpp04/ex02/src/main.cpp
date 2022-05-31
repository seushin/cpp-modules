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
		c->makeSound();
		std::cout << d->getType() << std::endl;
		d->makeSound();

		delete c;
		delete d;
	}
	std::cout << std::string(50, '-') << std::endl;
	{
		// const Animal *meta = new Animal();
		// compile error!
	}

	return (0);
}
