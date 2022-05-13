#include "Point.hpp"
#include <iostream>

int main()
{
	Point a;
	Point b(1.0f, 1.0f);

	a = b;
	std::cout << a << std::endl;
	return (0);
}
