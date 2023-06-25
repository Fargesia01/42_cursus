#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): Form("RobotomyRequestForm", 72, 45), _target("")
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm base constructor." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): Form("SchrubberyCreationFrom", 72, 45), _target(src.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
	*this = src;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
	return ;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	std::cout << "RobotomyRequestForm assignation operator called." << std::endl;
	return (*this);
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	checkExe(executor);
	std::cout << "UNBEARABLE DRILL NOIIIISE." << std::endl;
	if (std::rand() % 2)
		std::cout << this->_target << " was robotomized with success!" << std::endl;
	else
		std::cout << "Failed to robotize " << this->_target << std::endl;
	return ;
}
