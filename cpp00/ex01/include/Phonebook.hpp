/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:16:56 by seushin           #+#    #+#             */
/*   Updated: 2021/12/03 13:05:46 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	void	print_divider(void);
	void	print_row(int index);
	void	print_contact_list(void);

	void	print_detail_info(int index);
	void	search_contact_by_index(void);
};

#endif // !PHONEBOOK_HPP
