#include "iter.hpp"
#include <iostream>

template<typename T>
void f(T &a)
{
	std::cout << a << std::endl;
}

int main()
{
	{
		int arr[] = { 1, 2, 3, 4, 5 };
		int len = 5;

		iter(arr, len, f<int>);
	}
	{
		std::string arr[] = { "hello", "world", "!" };
		int len = 3;

		iter(arr, len, f);
	}

	return (0);
}
