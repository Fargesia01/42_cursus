#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal default constructor." << std::endl;
	this->type = "Wrong animal";
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal &src)
{
	std::cout << "Wrong Animal copy constructor." << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Wrong Animal destructor." << std::endl;
	return ;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal &src)
{
	std::cout << "Wrong Animal assignation operator called." << std::endl;
	this->type = src.type;
	return (*this);
}

std::string const	WrongAnimal::getType()
{
	return (this->type);
}

void const	WrongAnimal::makeSound()
{
	std::cout << "Random Wrong animal noise." << std::endl;
	return ;
}
