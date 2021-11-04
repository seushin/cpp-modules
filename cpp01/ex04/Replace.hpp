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

	std::string	&replaceLine(
			std::string &line, const std::string &src, const std::string &dst
			);
};

#endif // !REPLACE_HPP
