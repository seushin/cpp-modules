#include "Harl.hpp"
#include <iostream>

const std::string Harl::levels[LEVEL_COUNT] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
};
const Harl::HarlFuncPTR Harl::funcPTRs[LEVEL_COUNT] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
};

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
			  << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl
			  << "I cannot believe adding extra bacon costs more money."
			  << " You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			  << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl
			  << "I think I deserve to have some extra bacon for free."
			  << " I’ve been coming for years whereas you started working here since last month."
			  << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl
			  << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

E_LEVEL Harl::findLevel(const std::string &level)
{

	for (int i = 0; i < LEVEL_COUNT; ++i)
	{
		E_LEVEL l = static_cast<E_LEVEL>(i);

		if (level == levels[l])
			return (l);
	}
	return (LEVEL_COUNT);
}

void Harl::complain(std::string level)
{
	const E_LEVEL filter = findLevel(level);

	switch (filter)
	{
		case DEBUG_LEVEL:
			(this->*funcPTRs[DEBUG_LEVEL])();
			std::cout << std::endl;
		case INFO_LEVEL:
			(this->*funcPTRs[INFO_LEVEL])();
			std::cout << std::endl;
		case WARNING_LEVEL:
			(this->*funcPTRs[WARNING_LEVEL])();
			std::cout << std::endl;
		case ERROR_LEVEL:
			(this->*funcPTRs[ERROR_LEVEL])();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
					  << std::endl;
	}
}
