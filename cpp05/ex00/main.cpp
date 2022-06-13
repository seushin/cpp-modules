#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main()
{
	try
	{
		std::cout << "test non-exception" << std::endl;
		Bureaucrat jim("jim", 1);
		Bureaucrat bob("bob", 150);

		std::cout << jim << std::endl;
		std::cout << bob << std::endl;

		jim.decreaseGrade();
		bob.increaseGrade();

		std::cout << jim << std::endl;
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		// never print this
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "test constructor throw too high exception" << std::endl;
		Bureaucrat bob("bob", 0);

		// never print this
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "test constructor throw too low exception" << std::endl;
		Bureaucrat bob("bob", 151);

		// never print this
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "test increment func throw too high exception" << std::endl;
		Bureaucrat bob("bob", 1);

		bob.increaseGrade();
		// never print this
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "test decrement func throw too low exception" << std::endl;
		Bureaucrat bob("bob", 150);

		bob.decreaseGrade();
		// never print this
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
