#include <cmath>
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : fixed_point(n << fractional_bit)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n)
	: fixed_point(static_cast<int>(roundf(n * (1 << fractional_bit))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	return (fixed_point);
}

void	Fixed::setRawBits(const int raw)
{
	fixed_point = raw;
}

float	Fixed::toFloat(void) const
{
	int	rawBits = getRawBits();

	return (static_cast<float>(rawBits) / (1 << fractional_bit));
}

int	Fixed::toInt(void) const
{
	int	rawBits = getRawBits();

	return (rawBits >> fractional_bit);
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Assignation operator called " << std::endl;
	fixed_point = rhs.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &f)
{
	return (out << f.toFloat());
}
