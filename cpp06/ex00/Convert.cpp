#include "Convert.hpp"
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <sstream>

Convert::Convert() : value_(0) {}

Convert::Convert(const std::string &input)
{
	char *end;

	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		value_ = static_cast<double>(input[0]);
	else
	{
		value_ = std::strtod(input.c_str(), &end);
		if (value_ == HUGE_VAL && errno == ERANGE)
			throw OutOfRangeException();
		if (*end != '\0' && std::strcmp(end, "f") != 0)
			throw WrongInputException();
	}
}

Convert::Convert(const Convert &other)
{
	*this = other;
}

Convert &Convert::operator=(const Convert &rhs)
{
	value_ = rhs.value_;
	return (*this);
}

Convert::~Convert() {}

char Convert::toChar() const
{
	if (value_ < std::numeric_limits<char>::min() || value_ > std::numeric_limits<char>::max())
		throw OutOfRangeException();
	if (isInf() || isNan())
		throw ConvertImpossibleException();
	return (static_cast<char>(value_));
}

int Convert::toInt() const
{
	if (value_ < std::numeric_limits<int>::min() || value_ > std::numeric_limits<int>::max())
		throw OutOfRangeException();
	if (isInf() || isNan())
		throw ConvertImpossibleException();
	return (static_cast<int>(value_));
}

float Convert::toFloat() const
{
	if (!isInf() && !isNan() && value_ != 0)
	{
		if (value_ < -std::numeric_limits<float>::max() ||
			value_ > std::numeric_limits<float>::max())
			throw OutOfRangeException();
	}
	return (static_cast<float>(value_));
}

double Convert::toDouble() const
{
	return (value_);
}

bool Convert::isNan() const
{
	return (value_ != value_);
}

bool Convert::isInf() const
{
	return (value_ == INFINITY || value_ == -INFINITY);
}

const char *Convert::WrongInputException::what() const throw()
{
	return ("wrong input");
}

const char *Convert::ConvertImpossibleException::what() const throw()
{
	return ("impossible");
}

const char *Convert::OutOfRangeException::what() const throw()
{
	return ("out of range");
}

std::string Convert::printChar() const
{
	std::stringstream ss;

	ss << "char: ";
	try
	{
		char c = toChar();

		if (!std::isprint(c))
			ss << C_NOND;
		else
			ss << "'" << c << "'";
	}
	catch (const std::exception &)
	{
		ss << "impossible";
	}
	return (ss.str());
}

std::string Convert::printInt() const
{
	std::stringstream ss;

	ss << "int: ";
	try
	{
		int i = toInt();

		ss << i;
	}
	catch (const std::exception &)
	{
		ss << "impossible";
	}
	return (ss.str());
}

std::string Convert::printFloat() const
{
	std::stringstream ss;

	ss << "float: ";
	try
	{
		float f = toFloat();

		if (isInf())
			ss << std::showpos << f << "f";
		else if (f == std::floor(f))
			ss << f << ".0f";
		else
			ss << f << "f";
	}
	catch (const std::exception &)
	{
		ss << "impossible";
	}
	return (ss.str());
}

std::string Convert::printDouble() const
{
	std::stringstream ss;

	ss << "double: ";
	try
	{
		double d = toDouble();

		if (isInf())
			ss << std::showpos << d;
		else if (d == std::floor(d))
			ss << d << ".0";
		else
			ss << d;
	}
	catch (const std::exception &)
	{
		ss << "impossible";
	}
	return (ss.str());
}

std::ostream &operator<<(std::ostream &o, const Convert &conv)
{
	o << conv.printChar() << std::endl
	  << conv.printInt() << std::endl
	  << conv.printFloat() << std::endl
	  << conv.printDouble();

	return (o);
}
