#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap bob("Bob");
	FragTrap alice("Alice");

	bob.guardGate();
	alice.attack("bob");
	bob.takeDamage(150);
	alice.highFivesGuys();
}
