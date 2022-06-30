#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template<typename Container>
typename Container::iterator easyfind(Container &c, int value)
{
	typename Container::iterator res;

	res = find(c.begin(), c.end(), value);
	if (res == c.end())
		throw std::range_error("easyfind: value is out of range");
	return (res);
}

#endif // !EASYFIND_HPP
