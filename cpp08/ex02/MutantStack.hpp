#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <cstddef>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {}

	MutantStack(const MutantStack &other)
	{
		*this = other;
	}

	MutantStack &operator=(const MutantStack &rhs)
	{
		std::stack<T>::c = rhs.c;

		return (*this);
	}
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin()
	{
		return (std::stack<T>::c.begin());
	}

	iterator end()
	{
		return (std::stack<T>::c.end());
	}
};

#endif // !MUTANTSTACK_HPP
