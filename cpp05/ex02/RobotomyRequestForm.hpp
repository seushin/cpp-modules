#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <string>

class RobotomyRequestForm :public Form
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
	~RobotomyRequestForm();

	void execute(const Bureaucrat &executor) const;

private:
	std::string target_;
};

#endif// !ROBOTOMYREQUESTFORM_HPP
