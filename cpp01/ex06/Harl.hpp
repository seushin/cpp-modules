#ifndef HARL_HPP
#define HARL_HPP

#include <string>

enum E_LEVEL
{
	DEBUG_LEVEL,
	INFO_LEVEL,
	WARNING_LEVEL,
	ERROR_LEVEL,
	LEVEL_COUNT,
};

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
	E_LEVEL findLevel(const std::string &level);
};

#endif//HARL_HPP
