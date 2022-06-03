#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

class Form
{
public:
	Form();
	Form(std::string name, unsigned int signGrade, unsigned int execGrade);
	Form(const Form &other);
	~Form();
	void beSigned(const Bureaucrat &bur);
	const std::string &getName() const;
	bool getSigned() const;
	unsigned int getRequiredSignGrade() const;
	unsigned int getRequiredExecuteGrade() const;

	class GradeTooHighException: public std::exception
	{
		const char *what() const throw()
		{
			return ("Grade too high");
		}
	};
	class GradeTooLowException: public std::exception
	{
		const char *what() const throw()
		{
			return ("Grade too low");
		}
	};

private:
	const std::string name_;
	bool signed_;
	const unsigned int requiredSignGrade_;
	const unsigned int requiredExecuteGrade_;

	Form &operator=(const Form &rhs);
};

std::ostream &operator<<(std::ostream &o, const Form &f);

#endif// !FORM_HPP
