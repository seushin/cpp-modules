#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : raw_(0) {}

Fixed::Fixed(const int n)
{
	int fixed = n << fracBit_;

	raw_ = fixed;
}

Fixed::Fixed(const float n)
{
	float fixed = std::roundf(n * (1 << fracBit_));

	raw_ = static_cast<int>(fixed);
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	raw_ = rhs.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return (raw_ > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (raw_ < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (raw_ >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (raw_ <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (raw_ == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (raw_ != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;

	result.setRawBits(raw_ + rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;

	result.setRawBits(raw_ - rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed result;
	long long value;

	value = static_cast<long long>(raw_) * rhs.getRawBits();
	value >>= fracBit_;
	result.setRawBits(value);
	return (result);
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed result;
	long long value;

	value = static_cast<long long>(raw_) << fracBit_;
	value /= rhs.getRawBits();
	result.setRawBits(value);
	return (result);
}

Fixed &Fixed::operator++()
{
	++raw_;
	return (*this);
}

Fixed &Fixed::operator--()
{
	--raw_;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed prev = *this;

	operator++();
	return (prev);
}

Fixed Fixed::operator--(int)
{
	Fixed prev = *this;

	operator--();
	return (prev);
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return (o);
}

Fixed::~Fixed() {}

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

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}
