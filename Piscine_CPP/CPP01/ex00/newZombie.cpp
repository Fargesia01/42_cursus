#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie	*newDead = new Zombie(name);

	return (newDead);
}
