#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <ostream>
#include <string>

#define BU_GRADE_MAX 1
#define BU_GRADE_MIN 150

class Form;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, unsigned int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();
	const std::string &getName() const;
	unsigned int getGrade() const;
	void increaseGrade();
	void decreaseGrade();
	void signForm(Form &form);
	void executeForm(const Form &form);

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	const std::string name_;
	unsigned int grade_;
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);

#endif // !BUREAUCRAT_HPP
