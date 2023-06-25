#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const name): _name(name)
{
	std::cout << "Default constructor called" << std::endl;
	this->_hit_p = 10;
	this->_energy_p = 10;
	this->_atk_dmg = 0;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Desctuctor called" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hit_p = src._hit_p;
	this->_energy_p = src._energy_p;
	this->_atk_dmg = src._atk_dmg;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_p <= 0 || this->_hit_p <= 0)
	{
		std::cout << this->_name << " can't attack!" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks " << target << ", dealing " 
		<< this->_atk_dmg << " points of damage!" << std::endl;
	this->_energy_p--;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_name << " takes " << amount << " damage points!" << std::endl;
	this->_hit_p -= amount;
	if (this->_hit_p < 0)
		this->_hit_p = 0;
	if (this->_hit_p == 0)
		std::cout << this->_name << " is now dead!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_p <= 0 || this->_hit_p <= 0)
	{
		std::cout << this->_name << " is unable to heal himself!" << std::endl;
		return ;
	}
	std::cout << this->_name << " heals himself for " << amount << " points of damage!" << std::endl;
	this->_energy_p--;
	this->_hit_p += amount;
	if (this->_hit_p > 10)
		this->_hit_p = 10;
	std::cout << this->_name << " now has " << this->_hit_p << " health points." << std::endl;
	return ;
}
