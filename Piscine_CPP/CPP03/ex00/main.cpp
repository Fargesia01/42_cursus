#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap bob("Bob");
	ClapTrap alice("Alice");

	bob.attack("Alice");
	alice.takeDamage(20);
	alice.beRepaired(5);

	return (0);
}
