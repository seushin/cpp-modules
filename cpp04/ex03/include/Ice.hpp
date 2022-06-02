#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define ICE_DEFAULT_TYPE "ice"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &other);
	Ice &operator=(const Ice &rhs);
	~Ice();

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif// !ICE_HPP
