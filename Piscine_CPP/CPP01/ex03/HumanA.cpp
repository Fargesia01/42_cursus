#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _weapon(weapon)
{
	std::cout << "Human A default constructor called!" << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "Human A destructor called!" << std::endl;
	return ;
}

void	HumanA::attack() const
{
	std::cout << this->_name << " attacks with their weapon " << this->_weapon.getType() << std::endl;
	return ;
}
