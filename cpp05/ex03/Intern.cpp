#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &)
{
	return (*this);
}

Intern::~Intern() {}

enum EForm
{
	shrubberyCreation,
	robotomyRequest,
	presidentialPardon,
	formLength,
};

EForm searchForm(const std::string &name)
{
	std::string table[formLength];

	table[shrubberyCreation] = "shrubbery creation";
	table[robotomyRequest] = "robotomy request";
	table[presidentialPardon] = "presidential pardon";

	for (int i = 0; i < formLength; ++i)
	{
		if (table[i].compare(name) == 0)
			return ((EForm) i);
	}
	return (formLength);
}

Form *Intern::makeForm(const std::string &name, const std::string &target)
{
	Form *res;
	EForm found;

	res = NULL;
	found = searchForm(name);
	switch (found)
	{
		case shrubberyCreation:
			res = new ShrubberyCreationForm(target);
			break;
		case robotomyRequest:
			res = new RobotomyRequestForm(target);
			break;
		case presidentialPardon:
			res = new PresidentialPardonForm(target);
			break;
		case formLength:
		default:
			throw NotFoundFormException();
	}
	std::cout << "Intern creates " << name << std::endl;
	return (res);
}

const char* Intern::NotFoundFormException::what() const throw()
{
	return ("Not found form name");
}
