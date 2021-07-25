#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact()
{
	for (int i = 0; i < size(); ++i)
		info[i] = "";
}

void	Contact::set_info(std::string str, int type)
{
	info[type] = str;
}

std::string	Contact::get_info(int type)
{
	return (info[type]);
}

int	Contact::size(void)
{
	return (info_size);
}

std::string	Contact::type_to_str(int type)
{
	if (type == C_FIRST_NAME)
		return ("first name");
	else if (type == C_LAST_NAME)
		return ("last name");
	else if (type == C_NICKNAME)
		return ("nickname");
	else if (type == C_PHONE_NUMBER)
		return ("phone number");
	else if (type == C_SECRET)
		return ("darkest secret");
	else
		return ("undefined type!");
}
