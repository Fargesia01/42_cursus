#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("")
{
	std::cout << "Bureaucrat default constructor." << std::endl;
	this->_grade = 150;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "Bureaucrat base constructor." << std::endl;
	checkGrade();
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called." << std::endl;
	return ;
}

Bureaucrat &	Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat assignation operator called." << std::endl;
	this->_grade = src.getGrade();
	return (*this);
}

const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::addGrade(int amount)
{
	std::cout << "Adding " << amount << " grades to the bureaucrat." << std::endl;
	this->_grade -= amount;
	checkGrade();
	return ;
}

void	Bureaucrat::lowGrade(int amount)
{
	std::cout << "Removing " << amount << " grades to the bureaucrat." << std::endl;
	this->_grade += amount;
	checkGrade();
}

void	Bureaucrat::checkGrade() const
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &	operator<<(std::ostream &o, const Bureaucrat &src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return (o);
}
