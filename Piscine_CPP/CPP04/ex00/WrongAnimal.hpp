#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
	public :

		WrongAnimal(void);
		WrongAnimal(WrongAnimal &src);
		~WrongAnimal(void);

		WrongAnimal& operator=(WrongAnimal &src);

		std::string const	getType();
		void const	makeSound();

	protected :

		std::string	type;
};

#endif
