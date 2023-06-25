#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat: public Animal
{
	public :

		Cat(void);
		Cat(Cat &src);
		virtual ~Cat(void);

		Cat& operator=(const Cat &src);
		virtual Animal& operator=(const Animal &src);

		virtual Brain*	getBrain() const;
		virtual void	makeSound() const;

	private :

		Brain* brain;
};

#endif
