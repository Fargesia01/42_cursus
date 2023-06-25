#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class	Animal
{
	public :

		Animal(void);
		Animal(Animal &src);
		virtual ~Animal(void);

		Animal& operator=(Animal &src);

		std::string const	getType();
		virtual void const	makeSound();

	protected :

		std::string	type;
};

#endif
