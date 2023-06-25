#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public :

		Brain(void);
		Brain(Brain &src);
		~Brain(void);

		Brain& operator=(Brain &src);
	
		std::string ideas[100];
};

#endif
