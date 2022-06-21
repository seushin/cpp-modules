#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define MAX_VAL 750

int main()
{
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];

	std::srand(std::time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = std::rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	{
		Array<int> empty;

		if (empty.size() != 0)
		{
			std::cerr << "empty array's size must be zero" << std::endl;
		}

		try
		{
			empty[0];
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return (1);
		}
	}

	unsigned int size = numbers.size();
	if (size != MAX_VAL)
	{
		std::cerr << "size() is expected " << MAX_VAL << " but " << size << std::endl;
		return (1);
	}

	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = std::rand();
	}

	delete[] mirror;

	return (0);
}
