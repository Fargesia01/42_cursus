#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor." << std::endl;
	this->type = "animal";
	return ;
}

Animal::Animal(Animal &src)
{
	std::cout << "Animal copy constructor." << std::endl;
	return ;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor." << std::endl;
	return ;
}

Animal &	Animal::operator=(Animal &src)
{
	std::cout << "Animal assignation operator called." << std::endl;
	this->type = src.type;
	return (*this);
}

std::string const	Animal::getType()
{
	return (this->type);
}

void const	Animal::makeSound()
{
	std::cout << "Random animal noise." << std::endl;
	return ;
}
