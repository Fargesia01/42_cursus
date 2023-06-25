#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name), _max_hp(100)
{
	std::cout << "FragTrap default constructor called." << std::endl;
	this->_name = name;
	this->_hit_p = 100;
	this->_energy_p = 100;
	this->_atk_dmg = 30;
	return ;
}

FragTrap::FragTrap(FragTrap &src): ClapTrap(src), _max_hp(100)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called." << std::endl;
	return ;
}

FragTrap &	FragTrap::operator=(FragTrap &src)
{
	std::cout << "FragTrap assignation operator called." << std::cout;
	this->_name = src._name;
	this->_hit_p = src._hit_p;
	this->_energy_p = src._energy_p;
	this->_atk_dmg = src._atk_dmg;
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::string output;
	std::cout << "Please pretty, a high five? :(" << std::endl;
	std::cin >> output;
	while (output.compare("yes") != 0 && output.compare("no") != 0)
	{
		std::cout << "Yes or no? :(" << std::endl;
		std::cin >> output;
	}
	if (output.compare("yes") == 0)
		std::cout << "Yaay high five!!" << std::endl;
	else
		std::cout << "Ohhh... alright... :'(" << std::endl;
	return ;
}
