#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &rhs);
	~Fixed();
	int getRawBits() const;
	void setRawBits(const int raw);

private:
	int raw_;
	static const int fracBit_;
};

#endif//FIXED_HPP
