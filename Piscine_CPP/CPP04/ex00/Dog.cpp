#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor." << std::endl;
	this->type = "Dog";
	return ;
}

Dog::Dog(Dog &src)
{
	std::cout << "Dog copy constructor." << std::endl;
	*this = src;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called." << std::endl;
	return ;
}

Dog &	Dog::operator=(Dog &src)
{
	std::cout << "Dog assignation operator called." << std::endl;
	this->type = src.type;
	return (*this);
}

void const	Dog::makeSound()
{
	std::cout << "Woof Woof!" << std::endl;
	return ;
}
