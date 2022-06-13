#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main()
{
	try
	{
		std::cout << "** test ShrubberyCreationForm execute" << std::endl;
		ShrubberyCreationForm form("home");
		Bureaucrat me("me", 145);
		Bureaucrat boss("boss", 137);

		me.signForm(form);
		me.executeForm(form);
		boss.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "** test RobotomyRequestForm execute" << std::endl;
		RobotomyRequestForm form("shoes");
		Bureaucrat me("me", 70);
		Bureaucrat boss("boss", 45);

		me.signForm(form);
		me.executeForm(form);
		boss.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "** test PresidentialPardonForm execute" << std::endl;
		PresidentialPardonForm form("you");
		Bureaucrat me("me", 25);
		Bureaucrat boss("boss", 5);

		me.signForm(form);
		me.executeForm(form);
		boss.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
