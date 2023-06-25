#include "AAnimal.hpp"

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor." << std::endl;
	return ;
}

std::string	AAnimal::getType() const
{
	return (this->type);
}
