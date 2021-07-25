#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_INDEX 8

class Phonebook
{
public:
	Phonebook();
	void	add(void);
	void	search(void);

private:
	int	contact_size;
	Contact	contact[MAX_INDEX];

	void	print_header(void);
	void	print_divider(void);
	void	print_by_single_line(int index);
	void	print_all_contacts(void);

	void	print_contact_info(int index);
	void	search_contact_by_index(void);
};

#endif // !PHONEBOOK_HPP
