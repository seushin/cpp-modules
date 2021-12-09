/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:01:13 by seushin           #+#    #+#             */
/*   Updated: 2021/12/06 17:01:14 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>

class Replace
{
public:
	Replace(std::string fileName);
	~Replace();

	int	replace(const std::string &src, const std::string &dst);

private:
	std::string	inputFileName_;
	std::string	outputFileName_;

	std::string	&replaceLine(std::string &line, const std::string &src,
			const std::string &dst);
};

#endif // !REPLACE_HPP
