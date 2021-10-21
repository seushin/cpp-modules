#include <cmath>
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
	: fixed_point(0) {}

Fixed::Fixed(const int n)
	: fixed_point(n << fractional_bit) {}

Fixed::Fixed(const float n)
	: fixed_point(static_cast<int>(roundf(n * (1 << fractional_bit)))) {}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed() {}

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

Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return (rhs);
	return (lhs);
}

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

const Fixed	&Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs < rhs)
		return (rhs);
	return (lhs);
}

const Fixed	&Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	setRawBits(other.getRawBits());
	return (*this);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (getRawBits() != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	float	value = toFloat() + rhs.toFloat();

	return (Fixed(value));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	float	value = toFloat() - rhs.toFloat();

	return (Fixed(value));
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	float	value = toFloat() * rhs.toFloat();

	return (Fixed(value));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	float	value = toFloat() / rhs.toFloat();

	return (Fixed(value));
}

Fixed	&Fixed::operator++()
{
	int rawBits = getRawBits();

	setRawBits(++rawBits);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old = *this;

	operator++();
	return (old);
}

Fixed	&Fixed::operator--()
{
	int rawBits = getRawBits();

	setRawBits(--rawBits);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old = *this;

	operator--();
	return (old);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &f)
{
	return (out << f.toFloat());
}
