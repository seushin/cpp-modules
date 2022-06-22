#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>

Span::Span() : maxLength_(0) {}

Span::Span(unsigned int n) : maxLength_(n) {}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &rhs)
{
	numbers_ = rhs.numbers_;
	maxLength_ = rhs.maxLength_;
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (numbers_.size() == maxLength_)
		throw NoSpaceException();
	numbers_.push_back(n);
}

unsigned int Span::shortestSpan()
{
	unsigned int shortest;
	std::vector<int>::size_type length = numbers_.size();

	if (length < 2)
		throw NoSpanException();
	std::sort(numbers_.begin(), numbers_.end());
	shortest = UINT_MAX;
	for (int i = 0; i + 1 < length; ++i)
	{
		unsigned int span;

		span = static_cast<unsigned int>(
				std::labs(static_cast<long>(numbers_[i + 1]) - static_cast<long>(numbers_[i])));
		shortest = std::min(shortest, span);
	}
	return (shortest);
}

unsigned int Span::longestSpan()
{
	unsigned int longest;
	std::vector<int>::size_type length = numbers_.size();

	if (length < 2)
		throw NoSpanException();
	std::sort(numbers_.begin(), numbers_.end());
	longest = std::labs(static_cast<long>(numbers_[length - 1]) - static_cast<long>(numbers_[0]));
	return (longest);
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Span is empty");
}

const char *Span::NoSpaceException::what() const throw()
{
	return ("Span is full");
}
