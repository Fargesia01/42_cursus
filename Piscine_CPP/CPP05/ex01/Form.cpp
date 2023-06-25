#include "Form.hpp"

Form::Form(void): _name(""), _signed(false), _gToSign(150), _gToExe(150)
{
	std::cout << "Form default constructor called." << std::endl;
	return ;
}

Form::Form(std::string name, int gradeToSign, int gradeToExe): _name(name), 
	_gToSign(gradeToSign), _gToExe(gradeToExe)
{
	std::cout << "Form base constructor called." << std::endl;
	checkGrades();
	this->_signed = false;
	return ;
}

Form::Form(Form const &src): _name(src.getName()), _gToSign(src.getGradeToSigne()), _gToExe(src.getGradeToExe())
{
	std::cout << "Form copy constructor called." << std::endl;
	*this = src;
	return ;
}

Form::~Form(void)
{
	std::cout << "Form destructor called." << std::endl;
	return ;
}

Form &	Form::operator=(Form const &src)
{
	std::cout << "Form assignation operator called." << std::endl;
	this->_signed = src.getSigned();
	return (*this);
}

std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getGradeToSigne() const
{
	return (this->_gToSign);
}

int	Form::getGradeToExe() const
{
	return (this->_gToExe);
}

void	Form::beSigned(Bureaucrat const &src)
{
	if (src.getGrade() < this->_gToSign)
		this->_signed = true;
	else 
		throw Form::GradeTooLowException();
}

void	Form::checkGrades() const
{
	if (this->_gToSign > 150 || this->_gToExe > 150)
		throw Form::GradeTooLowException();
	else if (this->_gToSign < 1 || this->_gToExe < 1)
		throw Form::GradeTooHighException();
	return ;
}


std::ostream &	operator<<(std::ostream &o, const Form &src)
{
	o << src.getName() << ", form is signed = " << src.getSigned() << 
		". Grade to Sign is " << src.getGradeToSigne() << " and grade to execute is "
		<< src.getGradeToExe() << std::endl;
	return (o);
}
