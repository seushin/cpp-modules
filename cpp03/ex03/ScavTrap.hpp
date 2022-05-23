#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#define ST_HP 100
#define ST_EP 50
#define ST_AD 20

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &rhs);
	~ScavTrap();
	void attack(const std::string &target);
	void guardGate();
};

#endif//SCAVTRAP_HPP
