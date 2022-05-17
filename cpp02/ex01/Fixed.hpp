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
	~Fixed();
	int getRawBits() const;
	void setRawBits(const int raw);
	int toInt() const;
	float toFloat() const;

private:
	int raw_;
	static const int fracBit_;
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif//FIXED_HPP
