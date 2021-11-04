#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

struct Test
{
	bool	isSubtest;
	Test(std::string name, bool flag=false) : isSubtest(flag)
	{
		std::cout << ">> " << (isSubtest ? "\033[1;33m" : "Test: \033[1;32m")
			<< name
			<< "\033[0m" << std::endl;
	}
	~Test()
	{
		std::cout << "<<" << std::endl;
		if (isSubtest != true)
			std::cout << std::endl;
	}
};

int	main()
{
	{
		Test	t("Claptrap constructor & destructor");
		ClapTrap	clap1;
		ClapTrap	clap2("c2");
		ClapTrap	clap3(clap2);

		clap1.inspect();
		clap2.inspect();
		clap3.inspect();

		// call destructor
	}
	{
		Test	t("Claptrap functional");
		ClapTrap	clap1("c1");
		ClapTrap	clap2("c2");

		{
			Test	t("member function", true);
			clap1.attack(clap2.getName());
			clap1.takeDamage(4);
			clap1.beRepaired(2);
		}
		{
			Test	t("Assignment operator", true);
			std::cout << "clap2 = ";
			clap2.inspect();
			std::cout << "clap2 = clap1" << std::endl;
			clap2 = clap1;
			std::cout << "clap2 = ";
			clap2.inspect();
			// rename
			clap2.setName("c2");
		}
	}

	{
		Test	t("Scavtrap constructor & destructor");
		ScavTrap	scav1;
		ScavTrap	scav2("s2");
		ScavTrap	scav3(scav2);

		scav1.inspect();
		scav2.inspect();
		scav3.inspect();

		// call destructor
	}
	{
		Test	t("Scavtrap functional");
		ScavTrap	scav1("s1");
		ScavTrap	scav2("s2");

		{
			Test	t("member function", true);
			scav1.attack(scav2.getName());
			scav1.takeDamage(42);
			scav1.beRepaired(10);
			scav1.guardGate();
		}
		{
			Test	t("Assignment operator", true);
			std::cout << "scav2 = ";
			scav2.inspect();
			std::cout << "scav2 = scav1" << std::endl;
			scav2 = scav1;
			std::cout << "scav2 = ";
			scav2.inspect();
			// rename
			scav2.setName("s2");
		}
	}
	return (0);
}
