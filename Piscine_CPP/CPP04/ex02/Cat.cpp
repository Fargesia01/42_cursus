#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called." << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
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
	delete(this->brain);
	return ;
}

Cat &	Cat::operator=(const Cat &src)
{
	std::cout << "Cat assignation operator called." << std::endl;
	this->type = src.getType();
	*(this->brain) = *(src.getBrain());
	return (*this);
}

AAnimal &	Cat::operator=(const AAnimal &src)
{
	std::cout << "Cat override animal assignation operator" << std::endl;
	this->type = src.getType();
	*(this->brain) = *(src.getBrain());
	return (*this);
}

Brain*	Cat::getBrain() const
{
	return (this->brain);
}

void	Cat::makeSound() const
{
	std::cout << "Miaou!" << std::endl;
	return ;
}
