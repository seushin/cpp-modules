#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>
class Replace
{
public:
	Replace(std::string fileName);
	int replace(std::string dist, std::string source);

private:
	std::string fileName_;
};

#endif//REPLACE_HPP
