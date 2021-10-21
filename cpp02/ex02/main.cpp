#include <iostream>
#include <string>
#include "Fixed.hpp"

std::string	divider(30, '-');

int main()
{
	Fixed	zero(0);

	std::cout << "Fixed zero(0) == 0" << std::endl;

	std::cout << divider << std::endl;

	std::cout << "std::cout << zero++; => " << zero++ << std::endl;
	std::cout << "std::cout << zero; => " << zero << std::endl;
	std::cout << "std::cout << ++zero; => " << ++zero << std::endl;
	std::cout << "std::cout << --zero; => " << --zero << std::endl;

	std::cout << divider << std::endl;

	Fixed	const ft(42);
	Fixed	const f_t(4.2f);

	std::cout << "Fixed(42) => " << ft << std::endl;
	std::cout << "Fixed(4.2f) => " << f_t << std::endl;

	std::cout << divider << std::endl;

	std::cout << "Fixed(42) < Fixed(4.2f) => " << (ft < f_t) << std::endl;
	std::cout << "Fixed(42) > Fixed(4.2f) => " << (ft > f_t) << std::endl;
	std::cout << "Fixed(42) == Fixed(4.2f) => " << (ft == f_t) << std::endl;

	std::cout << divider << std::endl;

	std::cout << "Fixed(42) + Fixed(4.2f) => " << (ft + f_t) << std::endl;
	std::cout << "Fixed(42) - Fixed(4.2f) => " << (ft - f_t) << std::endl;
	std::cout << "Fixed(42) * Fixed(10) => " << (ft * Fixed(10)) << std::endl;
	std::cout << "Fixed(42) / Fixed(10) => " << (ft / Fixed(10)) << std::endl;

	std::cout << divider << std::endl;

	std::cout << "Fixed::max(Fixed(42), Fixed(4.2f)) => "
		<< Fixed::max(ft, f_t) << std::endl;
	std::cout << "Fixed::min(Fixed(42), Fixed(4.2f)) => "
		<< Fixed::min(ft, f_t) << std::endl;
	return (0);
}
