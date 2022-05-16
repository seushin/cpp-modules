#include "Point.hpp"
#include "bsp.hpp"
#include <iostream>

static void expect(bool a, bool b)
{
	if (a != b)
	{
		std::cout << "Test failed" << std::endl;
	}
}

static bool _bsp(const Point a, const Point b, const Point c, const Point p)
{
	static int count;
	bool res = bsp(a, b, c, p);

	std::cout << "case" << count++ << ": "
			  << p << " in "
			  << a << ", " << b << ", " << c
			  << " area? " << (res ? "true" : "false") << std::endl;

	return (res);
}

int main()
{
	{
		Point a(0.0f, 0.0f);
		Point b(1.0f, 0.0f);
		Point c(0.0f, 1.0f);

		Point p(0.5f, 0.5f);
		Point q(0.5f, 1.5f);

		expect(_bsp(a, b, c, p), true);
		expect(_bsp(b, a, c, p), true);
		expect(_bsp(c, a, b, p), true);
		expect(_bsp(c, b, a, p), true);

		expect(_bsp(a, b, c, q), false);
		expect(_bsp(b, a, c, q), false);
		expect(_bsp(c, a, b, q), false);
		expect(_bsp(c, b, a, q), false);
	}
	{
		Point b(0.0f, 0.0f);
		Point a(1.0f, 2.0f);
		Point c(2.0f, 0.0f);

		Point p(1.0f, 1.0f);
		Point q(2.0f, 2.0f);

		expect(_bsp(a, b, c, p), true);
		expect(_bsp(b, a, c, p), true);
		expect(_bsp(c, a, b, p), true);
		expect(_bsp(c, b, a, p), true);

		expect(_bsp(a, b, c, q), false);
		expect(_bsp(b, a, c, q), false);
		expect(_bsp(c, a, b, q), false);
		expect(_bsp(c, b, a, q), false);
	}
	return (0);
}
