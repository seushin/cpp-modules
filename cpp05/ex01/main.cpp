#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main()
{
	try
	{
		std::cout << "test grade too low exception" << std::endl;
		Form form("exceptForm", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "test grade too high exception" << std::endl;
		Form form("exceptForm", 0, 150);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "test sign form" << std::endl;
		Bureaucrat jim("jim", 10);
		Bureaucrat bob("bob", 150);

		std::cout << jim << std::endl;
		std::cout << bob << std::endl;

		Form testForm("testForm", 100, 10);
		Form copyForm(testForm);

		std::cout << testForm << std::endl;

		jim.signForm(testForm);
		std::cout << testForm << std::endl;

		bob.signForm(copyForm);
		std::cout << copyForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
