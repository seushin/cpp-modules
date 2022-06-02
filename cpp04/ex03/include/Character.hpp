#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

#define CH_MAX_SLOT_SIZE 4

class Character : public ICharacter
{
public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);
	Character &operator=(const Character &rhs);
	~Character();
	const std::string &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

private:
	std::string name_;
	AMateria *slot_[CH_MAX_SLOT_SIZE];
};

#endif// !CHARACTER_HPP
