#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name)
{
	std::cout << "Default constructor called!" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " just died." << std::endl;
	return ;
}

void	Zombie::announce() const
{
	std::cout << this->_name << ": Braiiiinzzzzz..." << std::endl;
	return ;
}
