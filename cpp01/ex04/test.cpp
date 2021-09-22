#include <fstream>
#include <iostream>
#include <string>

std::string	replace(std::string line, std::string src, std::string dst)
{
	std::string::size_type	loc = line.find(src);
	std::string::size_type	len = src.length();

	while (loc != std::string::npos)
	{
		line.erase(loc, len);
		line.insert(loc, dst);
		loc = line.find(src);
	}
	return (line);
}

int	replaceStringInFile(std::string fileName, std::string s1, std::string s2)
{
	std::ifstream	inputFile(fileName);
	if (inputFile.fail())
	{
		std::cout << "Error: inputFile open failed" << std::endl;
		return (1);
	}

	std::ofstream	outputFile(fileName.append(".replace"));
	if (outputFile.fail())
	{
		std::cout << "Error: outputFile open failed" << std::endl;
		return (1);
	}

	std::string	line;
	while (!inputFile.eof() && outputFile.good())
	{
		std::getline(inputFile, line);
		line = replace(line, s1, s2);
		outputFile << line << std::endl;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	status;

	if (argc == 4)
		status = replaceStringInFile(argv[1], argv[2], argv[3]);
	else
		status = 1;
	return (status);
}
