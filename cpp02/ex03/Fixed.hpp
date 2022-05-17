#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &rhs);
	bool operator>(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;
	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;
	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	~Fixed();
	int getRawBits() const;
	void setRawBits(const int raw);
	int toInt() const;
	float toFloat() const;
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);

private:
	int raw_;
	static const int fracBit_;
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif//FIXED_HPP
