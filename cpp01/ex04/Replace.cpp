/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:01:10 by seushin           #+#    #+#             */
/*   Updated: 2021/12/08 14:12:15 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "Replace.hpp"

Replace::Replace(std::string fileName)
	: inputFileName_(fileName),
	outputFileName_(fileName.append(".replace")) {}

Replace::~Replace() {}

std::string	&Replace::replaceLine(std::string &line, const std::string &src,
		const std::string &dst)
{
	if (src.size() == 0)
		return (line);

	std::string::size_type	pos = line.find(src);
	std::string::size_type	len = src.length();

	while (pos != std::string::npos)
	{
		line.erase(pos, len);
		line.insert(pos, dst);
		pos = line.find(src, pos);
	}
	return (line);
}

int	Replace::replace(const std::string &src, const std::string &dst)
{
	std::ifstream	ifs(inputFileName_.c_str());
	if (ifs.fail())
	{
		std::cerr << "Error: inputFile open failed" << std::endl;
		return (1);
	}

	std::ofstream	ofs(outputFileName_.c_str());
	if (ofs.fail())
	{
		std::cerr << "Error: outputFile open failed" << std::endl;
		return (1);
	}

	std::string	line;

	while (!ifs.eof() && ofs.good())
	{
		std::getline(ifs, line);
		line = replaceLine(line, src, dst);
		ofs << line;
		if (!ifs.eof())
			ofs << std::endl;
	}
	return (0);
}
