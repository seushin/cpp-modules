#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define CURE_DEFAULT_TYPE "cure"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &rhs);
	~Cure();

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif// !CURE_HPP
