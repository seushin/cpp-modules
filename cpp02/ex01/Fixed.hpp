#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &other);
	Fixed	&operator=(const Fixed &rhs);
	~Fixed();

	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int	toInt(void) const;

private:
	int	fixed_point;
	static const int	fractional_bit = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &f);
