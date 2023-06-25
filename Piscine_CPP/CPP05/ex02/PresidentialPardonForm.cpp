#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form("PresidentialPardonForm", 145, 137), _target("")
{
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):Form("PresidentialPardonForm", 145, 137), _target(target)
{
	std::cout << "PresidentialPardonForm base constructor." << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src): Form("SchrubberyCreationFrom", 145, 137), _target(src.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
	*this = src;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
	return ;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	std::cout << "PresidentialPardonForm assignation operator called." << std::endl;
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	checkExe(executor);
	std::cout << this->_target << " was pardonned by Zaphod Beeblebrox." << std::endl;
	return ;
}
