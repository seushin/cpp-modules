#include "AMateria.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	std::cout << std::string(50, '-') << std::endl;
	{
		Ice *i = new Ice();
		Character *enemy = new Character("enemy");

		i->use(*enemy);

		delete i;
		delete enemy;
	}
	std::cout << std::string(50, '-') << std::endl;
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter *me = new Character("me");

		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter *bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	return (0);
}
