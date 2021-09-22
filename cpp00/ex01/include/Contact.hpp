#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

#define C_FIRST_NAME 0
#define C_LAST_NAME 1
#define C_NICKNAME 2
#define C_PHONE_NUMBER 3
#define C_SECRET 4

class Contact
{
public:
	Contact();

	int	get_info_size(void);
	static std::string	get_type_label(int type);
	void	set_info(std::string str, int type);
	std::string	get_info(int type);

private:
	static const int	info_size = 5;
	std::string	info[info_size];
};

#endif // !CONTACT_HPP
