#include "Span.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>

int main()
{
	std::cout << "test basic functional" << std::endl;
	try
	{
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "test short/longest span exception" << std::endl;
	try
	{
		Span sp(2);

		sp.addNumber(42);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "test range addNumber" << std::endl;
	try
	{
		Span sp(10);

		int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		sp.addNumber(arr, arr + 10);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "test big number" << std::endl;
	try
	{
		Span sp(3);

		int arr[3] = {-2147483648, 0, 2147483647};
		sp.addNumber(arr, arr + (sizeof(arr) / sizeof(int)));

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "test 10,000 numbers" << std::endl;
	try
	{
		int length = 10000;
		Span sp(length);

		std::srand(std::time(NULL));
		for (int i = 0; i < length; ++i)
		{
			sp.addNumber(std::rand());
		}

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "test span 0 to 0" << std::endl;
	try
	{
		Span sp(2);

		sp.addNumber(0);
		sp.addNumber(0);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
