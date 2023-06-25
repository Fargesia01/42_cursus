#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class	AAnimal
{
	public :

		virtual ~AAnimal(void);

		virtual AAnimal& operator=(const AAnimal &src) = 0;

		std::string	getType() const;
		virtual void	makeSound() const = 0;
		virtual  Brain*	getBrain() const = 0;

	protected :

		std::string	type;
};

#endif
