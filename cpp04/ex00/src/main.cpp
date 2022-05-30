#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include <iostream>

void makeSound(const Animal *a)
{
	a->makeSound();
}

int main()
{
	{
		const Cat *c = new Cat();
		const Dog *d = new Dog();

		makeSound(c);
		makeSound(d);
	}
	{
		const Animal *meta = new Animal();
		const Animal *c = new Cat();
		const Animal *d = new Dog();

		std::cout << c->getType() << " " << std::endl;
		std::cout << d->getType() << " " << std::endl;
		c->makeSound();
		d->makeSound();
		meta->makeSound();
	}
	{
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *c = new WrongCat();
		const WrongAnimal *d = new WrongDog();

		std::cout << c->getType() << std::endl;
		std::cout << d->getType() << std::endl;
		c->makeSound();
		d->makeSound();
		meta->makeSound();
	}

	return (0);
}
