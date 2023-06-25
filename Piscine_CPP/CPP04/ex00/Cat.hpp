#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class	Cat: public Animal
{
	public :

		Cat(void);
		Cat(Cat &src);
		~Cat(void);

		Cat& operator=(Cat &src);

		void const	makeSound();

	private :


};

#endif
