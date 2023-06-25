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

Animal &	Animal::operator=(const Animal &src)
{
	std::cout << "Animal assignation operator called." << std::endl;
	this->type = src.type;
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "Random animal noise." << std::endl;
	return ;
}
