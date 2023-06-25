#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap bob("Bob");
	ClapTrap alice("Alice");

	bob.guardGate();
	bob.attack("alice");
	alice.attack("bob");
	bob.takeDamage(95);
	bob.beRepaired(30);
}
