#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
	public :

		WrongCat(void);
		WrongCat(WrongCat &src);
		~WrongCat(void);

		WrongCat& operator=(WrongCat &src);

		void const	makeSound();
};

#endif
