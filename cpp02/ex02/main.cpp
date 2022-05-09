#include "Fixed.hpp"
#include <iostream>

int main()
{
	{
		Fixed a;
		const Fixed b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}

	std::cout << std::endl
			  << "증감연산" << std::endl;
	{
		Fixed a;

		std::cout << a << std::endl;
		std::cout << --a << std::endl;
		std::cout << a << std::endl;
		std::cout << a-- << std::endl;
		std::cout << a << std::endl;
	}

	std::cout << std::endl
			  << "사칙연산" << std::endl;
	{
		Fixed a(100);
		Fixed b(42);
		Fixed c(42.42f);

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;

		std::cout << "a + b = " << (a + c) << std::endl;
		std::cout << "a - b = " << (a - c) << std::endl;
		std::cout << "a * b = " << (a * c) << std::endl;
		std::cout << "a / b = " << (a / c) << std::endl;
	}

	std::cout << std::endl
			  << "비교연산" << std::endl;
	{
		Fixed a(42);
		Fixed b(42.1f);

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;

		std::cout << "a < b == " << (a < b) << std::endl;
		std::cout << "a > b == " << (a > b) << std::endl;
		std::cout << "a <= b == " << (a <= b) << std::endl;
		std::cout << "a >= b == " << (a >= b) << std::endl;
		std::cout << "a == b == " << (a == b) << std::endl;
		std::cout << "a != b == " << (a != b) << std::endl;
	}

	std::cout << std::endl
			  << "max, min" << std::endl;
	{
		Fixed a(3.14f);
		Fixed b(4.42f);

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;

		std::cout << "max(a, b) " << Fixed::max(a, b) << std::endl;
		std::cout << "min(a, b) " << Fixed::min(a, b) << std::endl;
		}

	std::cout << std::endl
			  << "const max, min" << std::endl;
	{
		const Fixed a(3.14f);
		const Fixed b(4.42f);

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;

		std::cout << "max(a, b) " << Fixed::max(a, b) << std::endl;
		std::cout << "min(a, b) " << Fixed::min(a, b) << std::endl;
	}

	return (0);
}
