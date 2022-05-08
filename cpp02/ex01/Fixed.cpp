#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : raw_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	int fixed = n << fracBit_;

	raw_ = fixed;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	float fixed = std::roundf(n * (1 << fracBit_));

	raw_ = static_cast<int>(fixed);
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	raw_ = rhs.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return (o);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return (raw_);
}

void Fixed::setRawBits(const int raw)
{
	raw_ = raw;
}

int Fixed::toInt() const
{
	int value;

	value = raw_ >> fracBit_;
	return (value);
}

float Fixed::toFloat() const
{
	float value;

	value = static_cast<float>(raw_) / (1 << fracBit_);
	return (value);
}
