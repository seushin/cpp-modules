#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <string>

#define MS_MAX_SIZE 4

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &rhs);
	~MateriaSource();

	void learnMateria(AMateria *am);
	AMateria *createMateria(const std::string &type);

private:
	AMateria *storage[MS_MAX_SIZE];
};

#endif// !MATERIASOURCE_HPP
