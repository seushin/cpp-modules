#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("bob", club);

		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB john("john");

		john.setWeapon(club);
		john.attack();
		club.setType("some other type of club");
		john.attack();
	}
	return (0);
}
