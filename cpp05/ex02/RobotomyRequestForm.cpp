#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define RR_FORM_NAME "RobotomyRequest"
#define RR_SIGN_GRADE 72
#define RR_EXEC_GRADE 45

RobotomyRequestForm::RobotomyRequestForm()
	: Form(RR_FORM_NAME, RR_SIGN_GRADE, RR_EXEC_GRADE), target_("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: Form(RR_FORM_NAME, RR_SIGN_GRADE, RR_EXEC_GRADE), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: Form(other), target_(other.target_) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	target_ = rhs.target_;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	canExecute(executor);

	std::srand(std::time(nullptr));
	int randomInt = std::rand() % 2;

	std::cout << "* drilling noise *" << std::endl;
	if (randomInt)
		std::cout << target_ << " has been robotomized" << std::endl;
	else
		std::cout << "robotomy failed" << std::endl;
}
