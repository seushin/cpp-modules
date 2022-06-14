#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include <exception>
#include <string>

class Intern
{
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &rhs);
	~Intern();
	Form *makeForm(const std::string &name, const std::string &target);

	class NotFoundFormException : public std::exception
	{
		const char *what() const throw();
	};

private:
	enum EForm
	{
		shrubberyCreation,
		robotomyRequest,
		presidentialPardon,
		formLength,
	};
	EForm searchForm(const std::string &name);
};

#endif // !INTERN_HPP
