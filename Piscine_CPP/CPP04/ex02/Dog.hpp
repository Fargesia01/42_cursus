#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog: public	AAnimal
{
	public :

		Dog(void);
		Dog(Dog &src);
		virtual ~Dog(void);

		Dog& operator=(const Dog &src);
		virtual AAnimal& operator=(const AAnimal &src);

		virtual Brain* 	getBrain() const;
		virtual void	makeSound() const;

	private :

		Brain*  brain;
};

#endif
