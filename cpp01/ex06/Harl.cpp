#include "Harl.hpp"
#include <iostream>

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
	std::string labels[] = {
			"DEBUG",
			"INFO",
			"WARNING",
			"ERROR",
	};
	HarlFuncPTR funcPTRs[] = {
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error,
	};
	bool filter = false;

	for (int i = 0; i < 4; ++i)
	{
		if (filter || labels[i] == level)
		{
			filter = true;
			(this->*funcPTRs[i])();
			std::cout << std::endl;
		}
	}
	if (!filter)
		std::cout << "[ Probably complaining about insignificant problems ]"
				  << std::endl;
}
