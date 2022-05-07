#include "Replace.hpp"
#include <fstream>
#include <iostream>

Replace::Replace(std::string fileName) : fileName_(fileName) {}

std::string strReplace(std::string str, std::string dist, std::string source)
{
	std::string res;
	std::string::size_type pos = str.find(dist);

	while (pos != std::string::npos)
	{
		res.append(str, 0, pos);
		res.append(source);
		str = str.substr(pos + dist.size());
		pos = str.find(dist);
	}
	res.append(str);
	return (res);
}

int Replace::replace(std::string dist, std::string source)
{
	if (dist.size() == 0)
	{
		std::cout << "error: dist must be given" << std::endl;
		return (1);
	}

	std::ifstream inputFile(fileName_);

	if (inputFile.fail())
	{
		std::cout << "error: open file failed" << std::endl;
		return (1);
	}

	std::ofstream outputFile(fileName_ + ".replace", std::fstream::trunc);

	if (outputFile.fail())
	{
		std::cout << "error: create .replace file failed" << std::endl;
		return (1);
	}

	while (!inputFile.eof())
	{
		std::string line;

		std::getline(inputFile, line);
		outputFile << strReplace(line, dist, source);
		if (!inputFile.eof())
			outputFile << std::endl;
	}

	if (inputFile.bad())
	{
		std::cout << "error: read input file failed" << std::endl;
		return (1);
	}

	return (0);
}
