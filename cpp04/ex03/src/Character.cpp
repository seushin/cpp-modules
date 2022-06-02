#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character() : name_("someone")
{
	std::cout << "Character default constructor" << std::endl;
	for (int i = 0; i < CH_MAX_SLOT_SIZE; ++i)
	{
		slot_[i] = NULL;
	}
}

Character::Character(const std::string &name) : name_(name)
{
	std::cout << "Character string constructor" << std::endl;
	for (int i = 0; i < CH_MAX_SLOT_SIZE; ++i)
	{
		slot_[i] = NULL;
	}
}

Character::Character(const Character &other)
{
	std::cout << "Character copy constructor" << std::endl;
	for (int i = 0; i < CH_MAX_SLOT_SIZE; ++i)
	{
		slot_[i] = NULL;
	}
	*this = other;
}

Character &Character::operator=(const Character &rhs)
{
	name_ = rhs.name_;

	for (int i = 0; i < CH_MAX_SLOT_SIZE; ++i)
	{
		delete slot_[i];
		slot_[i] = NULL;

		if (rhs.slot_[i])
		{
			slot_[i] = rhs.slot_[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor" << std::endl;
	for (int i = 0; i < CH_MAX_SLOT_SIZE; ++i)
	{
		delete slot_[i];
		slot_[i] = NULL;
	}
}

const std::string &Character::getName() const
{
	return (name_);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < CH_MAX_SLOT_SIZE; ++i)
	{
		if (slot_[i] == NULL)
		{
			slot_[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	slot_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	AMateria *materia = slot_[idx];

	if (materia)
	{
		materia->use(target);
	}
}
