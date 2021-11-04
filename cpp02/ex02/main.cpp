#include <iostream>
#include <iomanip>
#include <string>
#include "Fixed.hpp"

int main()
{
	std::string	divider(30, '-');
	Fixed	zero(0);

	std::cout << "** 증감연산자" << std::endl;
	std::cout << "Fixed zero(0) == 0" << std::endl;
	std::cout << std::endl;

	std::cout << "std::cout << zero++; => " << zero++ << std::endl;
	std::cout << "std::cout << zero; => " << zero << std::endl;
	std::cout << "std::cout << ++zero; => " << ++zero << std::endl;
	std::cout << "std::cout << --zero; => " << --zero << std::endl;

	std::cout << divider << std::endl;

	Fixed	const ft(42);
	Fixed	const f_t(4.2f);

	std::cout << "** 비교연산자" << std::endl;
	std::cout << "Fixed(42) => " << ft << std::endl;
	std::cout << "Fixed(4.2f) => " << f_t << std::endl;
	std::cout << std::endl;

	std::cout << "Fixed(42) < Fixed(4.2f) => " << (ft < f_t) << std::endl;
	std::cout << "Fixed(42) > Fixed(4.2f) => " << (ft > f_t) << std::endl;
	std::cout << "Fixed(42) == Fixed(4.2f) => " << (ft == f_t) << std::endl;

	std::cout << divider << std::endl;

	std::cout << "** max, min" << std::endl;
	std::cout << "Fixed::max(Fixed(42), Fixed(4.2f)) => "
		<< Fixed::max(ft, f_t) << std::endl;
	std::cout << "Fixed::min(Fixed(42), Fixed(4.2f)) => "
		<< Fixed::min(ft, f_t) << std::endl;

	std::cout << divider << std::endl;

	float	a = 123456;
	float	b = 3.4567;

	std:: cout << std::fixed << std::setprecision(4);
	std::cout << "** 사칙연산" << std::endl;
	std::cout << "Fixed(" << a << ") == " << Fixed(a) << std::endl;
	std::cout << "Fixed(" << b << ") == " << Fixed(b) << std::endl;
	std::cout << std::endl;

	std::cout << a << " + " << b << " = ?" << std::endl;
	std::cout << "float: " << a + b << std::endl;
	std::cout << "Fixed: " << Fixed(a) + Fixed(b) << std::endl;
	std::cout << std::endl;

	std::cout << a << " - " << b << " = ?" << std::endl;
	std::cout << "float: " << a - b << std::endl;
	std::cout << "Fixed: " << Fixed(a) - Fixed(b) << std::endl;
	std::cout << std::endl;

	std::cout << a << " * " << b << " = ?" << std::endl;
	std::cout << "float: " << a * b << std::endl;
	std::cout << "Fixed: " << Fixed(a) * Fixed(b) << std::endl;
	std::cout << std::endl;

	std::cout << a << " / " << b << " = ?" << std::endl;
	std::cout << "float: " << a / b << std::endl;
	std::cout << "Fixed: " << Fixed(a) / Fixed(b) << std::endl;
	std::cout << std::endl;

	return (0);
}
