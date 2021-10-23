#include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap	&operator=(const ClapTrap &rhs);
	~ClapTrap();

	unsigned int	getHitPoint() const;
	unsigned int	getEnergyPoint() const;
	unsigned int	getAttackDamage() const;
	void	setHitPoint(unsigned int hitPoint);
	void	setEnergyPoint(unsigned int energyPoint);
	void	setAttackDamage(unsigned int attackDamage);

	void	attack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:
	std::string	name_;
	unsigned int	hitPoint_;
	unsigned int	energyPoint_;
	unsigned int	attackDamage_;
};
