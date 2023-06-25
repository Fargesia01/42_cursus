#include <iostream>
#include "Zombie.hpp"

int	main()
{
	std::cout << "Creating first zombie traditional way" << std::endl;
	Zombie first = Zombie("first");
	first.announce();

	std::cout << "Creating second zombie through newZombie()" << std::endl;
	Zombie *second = newZombie("second");
	second->announce();
	delete second;

	std::cout << "Creating third one randomly" << std::endl;
	randomChump("third");
	
	return (0);
}
