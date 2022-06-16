#include "Convert.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <cerrno>

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
		throw ConvertImpossibleException();
	if (isInf() || isNan())
		throw ConvertImpossibleException();
	return (static_cast<char>(value_));
}

int Convert::toInt() const
{
	if (value_ < std::numeric_limits<int>::min() || value_ > std::numeric_limits<int>::max())
		throw ConvertImpossibleException();
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
			throw ConvertImpossibleException();
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
	return ("Input cannot be parsed to double type");
}

const char *Convert::ConvertImpossibleException::what() const throw()
{
	return ("impossible");
}

const char *Convert::OutOfRangeException::what() const throw()
{
	return ("input is out of double type range");
}

void Convert::printChar(std::ostream &o) const
{
	o << "char: ";
	try
	{
		char c = toChar();

		if (!std::isprint(c))
			o << C_NOND;
		else
			o << "'" << c << "'";
	}
	catch (const ConvertImpossibleException &e)
	{
		o << e.what();
	}
	o << std::endl;
}

void Convert::printInt(std::ostream &o) const
{
	o << "int: ";
	try
	{
		int i = toInt();

		o << i;
	}
	catch (const ConvertImpossibleException &e)
	{
		o << e.what();
	}
	o << std::endl;
}

void Convert::printFloat(std::ostream &o) const
{
	o << "float: ";
	try
	{
		float f = toFloat();

		if (isInf())
			o << std::showpos << f << "f";
		else if (f == static_cast<int>(f))
			o << f << ".0f";
		else
			o << f << "f";
	}
	catch (const ConvertImpossibleException &e)
	{
		o << e.what();
	}
	o << std::endl;
}

void Convert::printDouble(std::ostream &o) const
{
	o << "double: ";
	try
	{
		double d = toDouble();

		if (isInf())
			o << std::showpos << d;
		else if (d == static_cast<int>(d))
			o << d << ".0";
		else
			o << d;
	}
	catch (const ConvertImpossibleException &e)
	{
		o << e.what();
	}
}

std::ostream &operator<<(std::ostream &o, const Convert &conv)
{
	conv.printChar(o);
	conv.printInt(o);
	conv.printFloat(o);
	conv.printDouble(o);

	return (o);
}
