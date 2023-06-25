#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class	Dog: public	Animal
{
	public :

		Dog(void);
		Dog(Dog &src);
		~Dog(void);

		Dog& operator=(Dog &src);

		void const	makeSound();
};

#endif
