#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &other);
	~Fixed();

	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int	toInt(void) const;

	static Fixed	&max(Fixed &lhs, Fixed &rhs);
	static Fixed	&min(Fixed &lhs, Fixed &rhs);
	static const Fixed	&max(const Fixed &lhs, const Fixed &rhs);
	static const Fixed	&min(const Fixed &lhs, const Fixed &rhs);

	Fixed	&operator=(const Fixed &rhs);

	bool	operator<(const Fixed &rhs) const;
	bool	operator>(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;
	bool	operator>=(const Fixed &rhs) const;
	bool	operator==(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;

	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;

	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);

private:
	int	fixed_point;
	static const int	fractional_bit = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &f);
