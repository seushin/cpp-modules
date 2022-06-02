#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor" << std::endl;
	for (int i = 0; i < MS_MAX_SOURCE_SIZE; ++i)
	{
		storage[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copy constructor" << std::endl;
	for (int i = 0; i < MS_MAX_SOURCE_SIZE; ++i)
	{
		storage[i] = NULL;
	}
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	for (int i = 0; i < MS_MAX_SOURCE_SIZE; ++i)
	{
		delete storage[i];
		storage[i] = NULL;

		if (rhs.storage[i])
		{
			storage[i] = rhs.storage[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor" << std::endl;
	for (int i = 0; i < MS_MAX_SOURCE_SIZE; ++i)
	{
		delete storage[i];
		storage[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria *am)
{
	for (int i = 0; i < MS_MAX_SOURCE_SIZE; ++i)
	{
		if (storage[i] == NULL)
		{
			storage[i] = am;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < MS_MAX_SOURCE_SIZE; ++i)
	{
		if (storage[i] == NULL)
			break;
		if (type.compare(storage[i]->getType()) == 0)
			return (storage[i]->clone());
	}
	return (NULL);
}
