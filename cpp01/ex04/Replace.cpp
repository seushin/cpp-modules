#include <fstream>
#include <iostream>
#include "Replace.hpp"

Replace::Replace(std::string fileName)
	: inputFileName_(fileName),
	outputFileName_(fileName.append(".replace")) {}

Replace::~Replace() {}

std::string	&Replace::replaceLine(
		std::string &line, const std::string &src, const std::string &dst
		)
{
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
	std::ifstream	ifs(inputFileName_);
	std::ofstream	ofs(outputFileName_);

	if (ifs.fail())
	{
		std::cerr << "Error: inputFile open failed" << std::endl;
		return (1);
	}
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
