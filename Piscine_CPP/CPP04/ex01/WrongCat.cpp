#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "Wrong Cat default constructor called." << std::endl;
	this->type = "Wrong Cat";
	return ;
}

WrongCat::WrongCat(WrongCat &src)
{
	std::cout << "Wrong Cat copy constructor called." << std::endl;
	*this = src;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Wrong Cat destructor called." << std::endl;
	return ;
}

WrongCat &	WrongCat::operator=(WrongCat &src)
{
	std::cout << "Wrong Cat assignation operator called." << std::endl;
	this->type = src.type;
	return (*this);
}

void const	WrongCat::makeSound()
{
	std::cout << "Miaou!" << std::endl;
	return ;
}
