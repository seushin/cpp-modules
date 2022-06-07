#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main()
{
	try
	{
		ShrubberyCreationForm form("home");
		Bureaucrat me("me", 140);

		me.signForm(form);
		form.execute(me);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		ShrubberyCreationForm form("home");
		Bureaucrat me("me", 140);
		Bureaucrat boss("boss", 10);

		me.signForm(form);
		form.execute(boss);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		RobotomyRequestForm form("home");
		Bureaucrat me("me", 40);
		Bureaucrat boss("boss", 10);

		me.signForm(form);
		form.execute(boss);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat jim("jim", 10);
		Bureaucrat bob("bob", 150);

		std::cout << jim << std::endl;
		std::cout << bob << std::endl;

		// Form testForm("testForm", 100, 10);
		// Form copyForm(testForm);

		// std::cout << testForm << std::endl;

		// jim.signForm(testForm);
		// std::cout << testForm << std::endl;

		// bob.signForm(copyForm);
		// std::cout << copyForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
