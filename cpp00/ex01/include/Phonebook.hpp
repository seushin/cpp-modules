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
	int	contact_count;
	int	column_width;
	Contact	contact[MAX_INDEX];

	void	print_header(void);
	void	print_divider(void);
	void	print_row(int index);
	void	print_contacts_by_table(void);

	void	print_contact_info(int index);
	void	search_contact_by_index(void);
};

#endif // !PHONEBOOK_HPP
