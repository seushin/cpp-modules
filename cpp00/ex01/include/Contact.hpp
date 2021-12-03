/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:16:53 by seushin           #+#    #+#             */
/*   Updated: 2021/12/03 14:08:18 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

typedef enum e_info
{
	C_FIRST_NAME = 0,
	C_LAST_NAME,
	C_NICKNAME,
	C_PHONE_NUMBER,
	C_SECRET,
	C_SIZE
}	t_info;

class Contact
{
public:
	Contact();

	static std::string	get_type_label(int type);
	void	set_info(std::string str, int type);
	std::string	get_info(int type);

private:
	std::string	info[C_SIZE];
};

#endif // !CONTACT_HPP
