#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
	std::cout << "Weapon default constructor called!" << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon desctuctor called!" << std::endl;
	return ;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}

const std::string&	Weapon::getType(void) const
{
	return (this->_type);
}
