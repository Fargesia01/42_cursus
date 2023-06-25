#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public :

		ClapTrap(std::string const name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap(void);

		ClapTrap& operator=(ClapTrap const &src);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected :

		std::string		_name;
		int				_hit_p;
		int				_energy_p;
		int				_atk_dmg;
		const int		_max_hp;
};

#endif
