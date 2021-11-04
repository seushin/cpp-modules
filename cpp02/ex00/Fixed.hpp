#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &);
	Fixed &operator=(const Fixed &);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int	fixed_point;
	static const int	fractional_bit = 8;
};

#endif // !FIXED_HPP
