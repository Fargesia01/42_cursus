#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat: public AAnimal
{
	public :

		Cat(void);
		Cat(Cat &src);
		virtual ~Cat(void);

		Cat& operator=(const Cat &src);
		virtual AAnimal& operator=(const AAnimal &src);

		virtual Brain*	getBrain() const;
		virtual void	makeSound() const;

	private :

		Brain* brain;
};

#endif
