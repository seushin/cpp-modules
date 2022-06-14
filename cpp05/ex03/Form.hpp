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
	Form &operator=(const Form &rhs);
	virtual ~Form();
	void beSigned(const Bureaucrat &bur);
	void canExecute(const Bureaucrat &executor) const;
	virtual void execute(const Bureaucrat &executor) const = 0;

	const std::string &getName() const;
	bool getSigned() const;
	unsigned int getRequiredSignGrade() const;
	unsigned int getRequiredExecuteGrade() const;

	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
	class MustBeSignedException : public std::exception
	{
		const char *what() const throw();
	};

private:
	const std::string name_;
	bool signed_;
	const unsigned int requiredSignGrade_;
	const unsigned int requiredExecuteGrade_;
};

std::ostream &operator<<(std::ostream &o, const Form &f);

#endif // !FORM_HPP
