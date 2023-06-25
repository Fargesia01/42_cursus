#include "Zombie.hpp"

Zombie::Zombie(): _name("default")
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

void	Zombie::set_name(std::string name)
{
	this->_name = name;
	return ;
}
