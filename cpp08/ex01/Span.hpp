#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

class Span
{
public:
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &rhs);
	~Span();

	template<typename Iterator>
	void addNumber(Iterator begin, Iterator end)
	{
		if (numbers_.size() + (end - begin) > maxLength_)
			throw NoSpaceException();
		numbers_.insert(numbers_.end(), begin, end);
	}
	void addNumber(int n);

	unsigned int shortestSpan();
	unsigned int longestSpan();

	class NoSpaceException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	std::vector<int> numbers_;
	unsigned int maxLength_;
};

#endif // !SPAN_HPP
