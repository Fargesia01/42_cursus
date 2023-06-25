#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default contructor" << std::endl;
	return ;
}

Brain::Brain(Brain &src)
{
	std::cout << "Brain copy constructor" << std::endl;
	*this = src;
	return ;
}

Brain::~Brain(void)
{
	std::cout << "Brain default desctructor." << std::endl;
	return ;
}

Brain &	Brain::operator=(Brain &src)
{
	std::cout << "Brain assignation opearator called." << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = src.ideas[i];
	}
	return (*this);
}
