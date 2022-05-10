#ifndef HARL_HPP
#define HARL_HPP

#include <string>

#define LEVEL_COUNT 4

class Harl
{
public:
	typedef void (Harl::*HarlFuncPTR)();
	void complain(std::string level);

private:
	void debug();
	void info();
	void warning();
	void error();
	static const std::string levels[LEVEL_COUNT];
	static const HarlFuncPTR funcPTRs[LEVEL_COUNT];
};

#endif//HARL_HPP
