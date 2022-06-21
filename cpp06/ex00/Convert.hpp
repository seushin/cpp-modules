#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <exception>
#include <ostream>
#include <string>

#define C_NOND "Non displayable"

class Convert
{
public:
	Convert();
	Convert(const std::string &input);
	Convert(const Convert &other);
	Convert &operator=(const Convert &rhs);
	~Convert();

	char toChar() const;
	int toInt() const;
	float toFloat() const;
	double toDouble() const;
	bool isNan() const;
	bool isInf() const;

	std::string printChar() const;
	std::string printInt() const;
	std::string printFloat() const;
	std::string printDouble() const;

	class WrongInputException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class ConvertImpossibleException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class OutOfRangeException : public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	double value_;
};

std::ostream &operator<<(std::ostream &o, const Convert &c);

#endif // !CONVERT_HPP
