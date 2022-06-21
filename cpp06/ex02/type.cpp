#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>

Base *generate(void)
{
	static time_t seed;
	Base *res;
	int random;

	if (seed == 0)
	{
		seed = std::time(NULL);
		std::srand(seed);
	}

	res = NULL;
	random = std::rand() % 3;
	switch (random)
	{
		case 0:
			res = new A();
			std::cout << "genereate A" << std::endl;
			break;
		case 1:
			res = new B();
			std::cout << "genereate B" << std::endl;
			break;
		case 2:
			res = new C();
			std::cout << "genereate C" << std::endl;
			break;
	}
	return (res);
}

void identify(Base *p)
{
	A *a;
	B *b;
	C *c;

	std::cout << "type is ";

	a = dynamic_cast<A *>(p);
	if (a != NULL)
	{
		std::cout << "A" << std::endl;
		return;
	}
	b = dynamic_cast<B *>(p);
	if (b != NULL)
	{
		std::cout << "B" << std::endl;
		return;
	}
	c = dynamic_cast<C *>(p);
	if (c != NULL)
	{
		std::cout << "C" << std::endl;
		return;
	}
	std::cout << "not found" << std::endl;
}

void identify(Base &p)
{
	std::cout << "type is ";

	try
	{
		p = dynamic_cast<A &>(p);

		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast)
	{}
	try
	{
		p = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::bad_cast)
	{}
	try
	{
		p = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::bad_cast)
	{}
	std::cout << "not found" << std::endl;
}
