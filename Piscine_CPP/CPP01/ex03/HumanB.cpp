#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	std::cout << "Default Human B constructor." << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << "Default Human B destructor." << std::endl;
	return ;
}

void	HumanB::attack() const
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their weapon " 
			<< this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " can't attack because he's got no weapon." << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	return ;
}
