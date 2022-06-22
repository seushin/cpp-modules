#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

template<typename T>
typename T::iterator easyfind(T &iterable, int value)
{
	typename T::iterator res;

	res = find(iterable.begin(), iterable.end(), value);
	if (res == iterable.end())
		throw std::exception();
	return (res);
}

#endif // !EASYFIND_HPP
