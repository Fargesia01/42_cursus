#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called." << std::endl;
	this->type = "Cat";
	return ;
}

Cat::Cat(Cat &src)
{
	std::cout << "Cat copy constructor called." << std::endl;
	*this = src;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called." << std::endl;
	return ;
}

Cat &	Cat::operator=(Cat &src)
{
	std::cout << "Cat assignation operator called." << std::endl;
	this->type = src.type;
	return (*this);
}

void const	Cat::makeSound()
{
	std::cout << "Miaou!" << std::endl;
	return ;
}
