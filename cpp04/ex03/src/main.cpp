#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
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
	std::cout << std::string(50, '-') << std::endl;
	{
		// test AMateria
		AMateria *ice = new Ice();
		Character *enemy = new Character("enemy");

		std::cout << std::endl
				  << "* clone ice" << std::endl;
		AMateria *clone = ice->clone();

		std::cout << std::endl
				  << "* ice type is "
				  << ice->getType() << std::endl;
		std::cout << std::endl
				  << "* clone type is "
				  << clone->getType() << std::endl;

		std::cout << std::endl
				  << "* use ice, cloned ice" << std::endl;
		ice->use(*enemy);
		clone->use(*enemy);

		delete ice;
		delete clone;
		delete enemy;
	}
	std::cout << std::string(50, '-') << std::endl;
	{
		// test Character copy & assignment operator
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		Character *bob = new Character("bob");
		bob->equip(src->createMateria("ice"));

		// copy
		Character *clone1 = new Character(*bob);

		// assign
		Character *clone2 = new Character();
		clone2->equip(src->createMateria("cure"));
		// test free before assignment
		*clone2 = *bob;

		// test copy
		std::cout << bob->getName() << std::endl;
		std::cout << clone1->getName() << std::endl;
		std::cout << clone2->getName() << std::endl;

		// test deep copy
		delete bob;
		clone1->use(0, *clone2);
		clone2->use(0, *clone1);

		delete src;
		delete clone1;
		delete clone2;
	}

	return (0);
}
