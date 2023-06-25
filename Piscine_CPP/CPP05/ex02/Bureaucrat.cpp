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

bool	Bureaucrat::signForm(Form &src) const
{
	if (src.getSigned())
	{
		std::cout << this->_name << " couldn't sign " << src.getName() 
			<< " because it is already signed." << std::endl;
		return (false);
	}
	try
	{
		src.beSigned(*this);
		std::cout << this->_name << " signed " << src.getName() << std::endl;
		return (true);
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cout << this->_name << " couldn't sign " << src.getName() 
			<< " because his grade is too low." << std::endl;
		return (false);
	}
}

bool	Bureaucrat::executeForm(Form &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed form " << form.getName() << std::endl;
		return (true);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (false);
	}
}

void	Bureaucrat::checkGrade() const
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

std::ostream &	operator<<(std::ostream &o, const Bureaucrat &src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return (o);
}
