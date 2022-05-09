#include "Replace.hpp"
#include <fstream>
#include <iostream>

Replace::Replace(std::string fileName) : fileName_(fileName) {}

std::string strReplace(std::string str, std::string dist, std::string source)
{
	std::string res;
	std::string::size_type startPos= 0;
	std::string::size_type pos = str.find(dist);

	while (pos != std::string::npos)
	{
		res.append(str, startPos, pos - startPos);
		res.append(source);
		startPos = pos + dist.size();
		pos = str.find(dist, startPos);
	}
	res.append(str, startPos, std::string::npos);
	return (res);
}

int Replace::replace(std::string dist, std::string source)
{
	if (dist.size() == 0)
	{
		std::cerr << "error: dist must be given" << std::endl;
		return (1);
	}

	std::ifstream inputFile(fileName_);
	std::ofstream outputFile;

	if (inputFile.fail())
	{
		std::cerr << "error: open file failed" << std::endl;
		return (1);
	}
	outputFile.open(fileName_ + ".replace", std::fstream::trunc);
	if (outputFile.fail())
	{
		std::cerr << "error: create .replace file failed" << std::endl;
		return (1);
	}

	std::string line;

	while (std::getline(inputFile, line) && outputFile.good())
	{
		if (!inputFile.eof())
			line.append("\n");
		outputFile << strReplace(line, dist, source);
	}

	if (inputFile.bad() || outputFile.fail())
	{
		std::cerr << "error: replace '" << dist << "' failed" << std::endl;
		return (1);
	}

	return (0);
}
