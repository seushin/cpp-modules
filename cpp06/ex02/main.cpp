#include "Base.hpp"
#include "type.hpp"
#include <iostream>

int main()
{
	Base *p1, *p2, *p3;

	p1 = generate();
	identify(p1);
	identify(*p1);

	p2 = generate();
	identify(p2);
	identify(*p2);

	p3 = generate();
	identify(p3);
	identify(*p3);

	delete p1;
	delete p2;
	delete p3;

	return (0);
}
