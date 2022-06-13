#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include <fstream>
#include <iostream>

#define SH_FORM_NAME "ShrubberyCreation"
#define SH_SIGN_GRADE 145
#define SH_EXEC_GRADE 137

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form(SH_FORM_NAME, SH_SIGN_GRADE, SH_EXEC_GRADE), target_("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: Form(SH_FORM_NAME, SH_SIGN_GRADE, SH_EXEC_GRADE), target_(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: Form(other), target_(other.target_)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	target_ = rhs.target_;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	canExecute(executor);

	std::ofstream output(target_ + "_shrubbery");
	std::string asciiTree = "————–*-*————–\n"
							"———–*—-*–*———–\n"
							"——–*–*—-*—–*–*—–\n"
							"—–*—–*—-*–*—-*——\n"
							"-*-*—*—*—-*—-*—*—-\n"
							"-*—–*–*—-*-*-.#–*—*–\n"
							"-*—*—–*-#.–.#-*—*——\n"
							"–*—–”#.–#:-#”-*-*—-*—-\n"
							"-*—*-*-”#.-##”——-*——-\n"
							"—*——-”###—————-\n"
							"————-”##—————-\n"
							"————-##.—————-\n"
							"————.##:—————-\n"
							"———–:###—————-\n"
							"———–;###—————-\n"
							"———-,####.—————\n"
							"/\\/\\.######.\\/\\/\\/\\—–\n";

	output << asciiTree;
}
