#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#define FT_HP 100
#define FT_EP 100
#define FT_AD 30

#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &rhs);
	~FragTrap();
	void highFivesGuys();
};

#endif//FRAGTRAP_HPP
