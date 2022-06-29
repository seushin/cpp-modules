#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <cstddef>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	// typedefs
	// clang-format off
	typedef typename std::stack<T>                                          base_container;
	typedef typename base_container::container_type::iterator               iterator;
	typedef typename base_container::container_type::const_iterator         const_iterator;
	typedef typename base_container::container_type::reverse_iterator       reverse_iterator;
	typedef typename base_container::container_type::const_reverse_iterator const_reverse_iterator;
	// clang-format on

	MutantStack() {}

	MutantStack(const MutantStack &other)
	{
		*this = other;
	}

	MutantStack &operator=(const MutantStack &rhs)
	{
		base_container::operator=(rhs);

		return (*this);
	}
	~MutantStack() {}

	iterator begin()
	{
		return (this->c.begin());
	}

	const_iterator begin() const
	{
		return (this->c.begin());
	}

	iterator end()
	{
		return (this->c.end());
	}

	const_iterator end() const
	{
		return (this->c.end());
	}

	reverse_iterator rbegin()
	{
		return (this->c.rbegin());
	}

	const_reverse_iterator rbegin() const
	{
		return (this->c.rbegin());
	}

	reverse_iterator rend()
	{
		return (this->c.rend());
	}

	const_reverse_iterator rend() const
	{
		return (this->c.rend());
	}
};

#endif // !MUTANTSTACK_HPP
