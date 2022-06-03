#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main()
{
	try
	{
		Bureaucrat jim("jim", 1);
		Bureaucrat bob("bob", 150);

		std::cout << jim << std::endl;
		std::cout << bob << std::endl;

		jim.decreaseGrade();
		bob.increaseGrade();

		std::cout << jim << std::endl;
		std::cout << bob << std::endl;

		Form task1("task1", 100, 10);

		std::cout << task1 << std::endl;

		jim.signForm(task1);
		bob.signForm(task1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
