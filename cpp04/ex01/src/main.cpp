#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	{
		const Animal *c = new Cat();
		const Animal *d = new Dog();

		delete c;
		delete d;
	}
	while (1) {}

	return (0);
}
