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

void Harl::complain(std::string level)
{
	const int len = sizeof(levels) / sizeof(std::string);

	for (int i = 0; i < len; ++i)
	{
		if (levels[i] == level)
		{
			(this->*funcPTRs[i])();
			return;
		}
	}
	std::cout << "[ level not found ]" << std::endl;
}
