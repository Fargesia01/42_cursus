#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog: public	Animal
{
	public :

		Dog(void);
		Dog(Dog &src);
		virtual ~Dog(void);

		Dog& operator=(const Dog &src);
		virtual Animal& operator=(const Animal &src);

		virtual Brain* 	getBrain() const;
		virtual void	makeSound() const;

	private :

		Brain*  brain;
};

#endif
