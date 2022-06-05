#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

Bureaucrat::Bureaucrat() : name_(""), grade_(BU_GRADE_MIN) {}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)
	: name_(name), grade_(grade)
{
	if (grade < BU_GRADE_MAX)
		throw GradeTooHighException();
	else if (grade > BU_GRADE_MIN)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	grade_ = rhs.grade_;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b)
{
	o << b.getName() << ", Bureaucrat grade " << b.getGrade() << ".";
	return (o);
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const
{
	return (name_);
}

unsigned int Bureaucrat::getGrade() const
{
	return (grade_);
}

void Bureaucrat::increaseGrade()
{
	if (grade_ <= BU_GRADE_MAX)
		throw GradeTooHighException();
	else
		grade_--;
}

void Bureaucrat::decreaseGrade()
{
	if (grade_ >= BU_GRADE_MIN)
		throw GradeTooLowException();
	else
		grade_++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
