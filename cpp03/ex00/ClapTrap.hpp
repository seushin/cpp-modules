#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <ostream>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &rhs);
	~ClapTrap();
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName() const;
	unsigned int getHitPoint() const;
	unsigned int getEnergyPoint() const;
	unsigned int getAttackDamage() const;

private:
	std::string name_;
	unsigned int hitPoint_;
	unsigned int energyPoint_;
	unsigned int attackDamage_;
};

std::ostream &operator<<(std::ostream &o, const ClapTrap &rhs);

#endif//CLAPTRAP_HPP
