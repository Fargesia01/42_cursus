#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default consrtuctor called" << std::endl;
	this->_whole = 0;
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_whole = src.getRawBits();
	return ;
}
Fixed::Fixed(int const nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_whole  = (nb << Fixed::_fp);
	return ;
}

Fixed::Fixed(float const nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->_whole = roundf(nb * (1 << Fixed::_fp));
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &	Fixed::operator=(Fixed const &src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_whole = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_whole);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_whole = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_whole / (float)(1 << Fixed::_fp));
}

int	Fixed::toInt(void) const
{
	return (this->_whole >> Fixed::_fp);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &src)
{
	o << src.toFloat();
	return (o);
}
