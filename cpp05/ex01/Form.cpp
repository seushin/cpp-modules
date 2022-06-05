#include "Form.hpp"

Form::Form()
	: name_("default-form"),
	  signed_(false),
	  requiredSignGrade_(100),
	  requiredExecuteGrade_(10) {}

Form::Form(std::string name, unsigned int signGrade, unsigned int execGrade)
	: name_(name),
	  signed_(false),
	  requiredSignGrade_(signGrade),
	  requiredExecuteGrade_(execGrade)
{
	if (requiredSignGrade_ < BU_GRADE_MAX || requiredExecuteGrade_ < BU_GRADE_MAX)
		throw GradeTooHighException();
	else if (requiredSignGrade_ > BU_GRADE_MIN || requiredExecuteGrade_ > BU_GRADE_MIN)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: name_(other.name_),
	  signed_(other.signed_),
	  requiredSignGrade_(other.requiredSignGrade_),
	  requiredExecuteGrade_(other.requiredExecuteGrade_) {}

Form &Form::operator=(const Form &)
{
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Form &f)
{
	o << f.getName() << ", " << (f.getSigned() ? "signed" : "unsigned")
	  << " form. requiredSignGrade(" << f.getRequiredSignGrade()
	  << ") requiredExecuteGrade(" << f.getRequiredExecuteGrade() << ")";
	return (o);
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() <= requiredSignGrade_)
		signed_ = true;
	else
		throw GradeTooLowException();
}

const std::string &Form::getName() const
{
	return (name_);
}

bool Form::getSigned() const
{
	return (signed_);
}

unsigned int Form::getRequiredSignGrade() const
{
	return (requiredSignGrade_);
}

unsigned int Form::getRequiredExecuteGrade() const
{
	return (requiredExecuteGrade_);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
