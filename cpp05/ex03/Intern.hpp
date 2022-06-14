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
};

#endif // !INTERN_HPP
