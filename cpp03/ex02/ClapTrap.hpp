#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
private:
	std::string	name_;
	unsigned int	hitPoint_;
	unsigned int	energyPoint_;
	unsigned int	attackDamage_;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap	&operator=(const ClapTrap &rhs);
	~ClapTrap();

	std::string	getName() const;
	unsigned int	getHitPoint() const;
	unsigned int	getEnergyPoint() const;
	unsigned int	getAttackDamage() const;
	void	setName(std::string name);
	void	setHitPoint(unsigned int hitPoint);
	void	setEnergyPoint(unsigned int energyPoint);
	void	setAttackDamage(unsigned int attackDamage);

	void	attack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	inspect(void) const;
};

#endif // !CLAPTRAP_HPP
