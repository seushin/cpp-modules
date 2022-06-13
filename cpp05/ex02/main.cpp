#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cassert>
#include <exception>
#include <iostream>

int main()
{
	try
	{
		assert("test ShrubberyCreationForm execute");
		ShrubberyCreationForm form("home");
		Bureaucrat me("me", 145);
		Bureaucrat boss("boss", 137);

		me.signForm(form);
		me.executeForm(form);
		boss.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		assert(false); // abort
	}

	try
	{
		assert("test RobotomyRequestForm execute");
		RobotomyRequestForm form("desk");
		Bureaucrat me("me", 70);
		Bureaucrat boss("boss", 45);

		me.signForm(form);
		me.executeForm(form);
		boss.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		assert(false); // abort
	}

	try
	{
		assert("test PresidentialPardonForm execute");
		PresidentialPardonForm form("you");
		Bureaucrat me("me", 25);
		Bureaucrat boss("boss", 5);

		me.signForm(form);
		me.executeForm(form);
		boss.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		assert(false); // abort
	}

	return (0);
}
