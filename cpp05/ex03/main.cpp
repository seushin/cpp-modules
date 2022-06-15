#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include <exception>
#include <iostream>

int main()
{
	try
	{
		std::cout << "** test intern" << std::endl;
		Bureaucrat me("me", 1);
		Form *form;
		Intern intern;

		form = intern.makeForm("robotomy request", "Bender");
		std::cout << "returned form: " << *form << std::endl;
		me.signForm(*form);
		me.executeForm(*form);
		delete form;
		std::cout << std::endl;

		form = intern.makeForm("shrubbery creation", "home");
		std::cout << "returned form: " << *form << std::endl;
		me.signForm(*form);
		me.executeForm(*form);
		delete form;
		std::cout << std::endl;

		form = intern.makeForm("presidential pardon", "you");
		std::cout << "returned form: " << *form << std::endl;
		me.signForm(*form);
		me.executeForm(*form);
		delete form;
		std::cout << std::endl;

		form = intern.makeForm("wrong form", "some target");
		std::cout << "returned form: " << *form << std::endl;
		me.signForm(*form);
		me.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	return (0);
}
