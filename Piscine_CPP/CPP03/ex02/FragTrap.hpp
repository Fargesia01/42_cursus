#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class	FragTrap: public ClapTrap
{
	public :

		FragTrap(std::string name);
		FragTrap(FragTrap &src);
		~FragTrap(void);

		FragTrap& operator=(FragTrap &src);

		void	highFivesGuys();

	private :

		const int	_max_hp;
};

#endif
