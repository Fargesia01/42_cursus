#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :

		ScavTrap(std::string const name);
		ScavTrap(ScavTrap &src);
		~ScavTrap(void);

		ScavTrap& operator=(ScavTrap &src);

		void	guardGate();
		void	attack(const std::string &target);

	private :

		const int	_max_hp;
};

#endif
