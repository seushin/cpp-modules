#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <vector>
#include <queue>

int main()
{
	std::vector<int> v;

	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}

	try
	{
		std::cout << *easyfind(v, 1) << std::endl;
		std::cout << *easyfind(v, 2) << std::endl;
		std::cout << *easyfind(v, 9) << std::endl;
		std::cout << *easyfind(v, 42) << std::endl;
	}
	catch (std::exception &)
	{
		std::cerr << "Not found" << std::endl;
	}

	std::queue<int> q;

	for (int i = 0; i < 10; ++i)
	{
		q.push(i);
	}

	try
	{
		std::cout << *easyfind(v, 1) << std::endl;
		std::cout << *easyfind(v, 2) << std::endl;
		std::cout << *easyfind(v, 9) << std::endl;
		std::cout << *easyfind(v, 42) << std::endl;
	}
	catch (std::exception &)
	{
		std::cerr << "Not found" << std::endl;
	}

	return (0);
}
