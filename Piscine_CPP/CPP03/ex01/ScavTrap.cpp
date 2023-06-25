#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const name): ClapTrap(name)
{
	std::cout << "ScavTrap default constructor called." << std::endl;
	this->_name = name;
	this->_max_hp = 100;
	this->_hit_p = 100;
	this->_energy_p = 50;
	this->_atk_dmg = 20;
	return ;
}

ScavTrap::ScavTrap(ScavTrap &src): ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called." << std::endl;
	return ;
}

ScavTrap &	ScavTrap::operator=(ScavTrap &src)
{
	std::cout << "ScavTrap assignation operator called." << std::endl;
	this->_name = src._name;
	this->_hit_p = src._hit_p;
	this->_energy_p = src._energy_p;
	this->_atk_dmg = src._atk_dmg;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energy_p <= 0 || this->_hit_p <= 0)
	{
		std::cout << this->_name << " can't attack!" << std::endl;
		return ;
	}
	std::cout << this->_name << " assaults " << target << ", making  " 
		<< this->_atk_dmg << " points of damage!" << std::endl;
	this->_energy_p--;
	return ;
}

void	ScavTrap::guardGate()
{
	std::cout << this->_name << " has entered the gate keeper mode." << std::endl;
	return ;
}
