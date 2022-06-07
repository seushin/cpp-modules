#include "PresidentialPardonForm.hpp"
#include <iostream>

#define PP_FORM_NAME "PresidentialParadon"
#define PP_SIGN_GRADE 25
#define PP_EXEC_GRADE 5

PresidentialPardonForm::PresidentialPardonForm()
	: Form(PP_FORM_NAME, PP_SIGN_GRADE, PP_EXEC_GRADE), target_("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: Form(PP_FORM_NAME, PP_SIGN_GRADE, PP_EXEC_GRADE), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: Form(other), target_(other.target_) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	target_ = rhs.target_;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	canExecute(executor);

	std::cout << target_ << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}
