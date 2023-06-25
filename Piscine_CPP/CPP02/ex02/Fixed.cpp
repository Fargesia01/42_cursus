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

Fixed	&Fixed::operator=(Fixed const &src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_whole = src.getRawBits();
	return (*this);
}

bool	Fixed::operator<(Fixed const &fp) const
{
	if (this->getRawBits()	< fp.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>(Fixed const &fp) const
{
	if (this->getRawBits() > fp.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(Fixed const &fp) const
{
	if (this->getRawBits() <= fp.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(Fixed const &fp) const
{
	if (this->getRawBits() >= fp.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(Fixed const &fp) const
{
	if (this->getRawBits() == fp.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(Fixed const &fp) const
{
	if (this->getRawBits() != fp.getRawBits())
		return (true);
	else
		return (false);
}

Fixed	Fixed::operator+(Fixed const &fp) const
{
	Fixed	tot;

	tot.setRawBits(this->getRawBits() + fp.getRawBits());
	return (tot);
}

Fixed	Fixed::operator-(Fixed const &fp) const
{
	Fixed	tot;

	tot.setRawBits(this->getRawBits() - fp.getRawBits());
	return (tot);
}

Fixed	Fixed::operator*(Fixed const &fp) const
{
	Fixed	tot;

	tot.setRawBits(this->getRawBits() * fp.getRawBits() / (1 << Fixed::_fp));
	return (tot);
}

Fixed	Fixed::operator/(Fixed const &fp) const
{
	Fixed	tot;

	tot.setRawBits(this->getRawBits() / fp.getRawBits() * (1 << Fixed::_fp));
	return (tot);
}

Fixed	Fixed::operator++()
{
	this->_whole++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);

	operator++();
	return (tmp);
}

Fixed	Fixed::operator--()
{
	this->_whole--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	operator--();
	return (tmp);
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

Fixed	&Fixed::min(Fixed &fp1, Fixed &fp2)
{
	if (fp1 > fp2)
		return (fp2);
	else
		return (fp1);
}

Fixed	&Fixed::max(Fixed &fp1, Fixed &fp2)
{
	if (fp1 > fp2)
		return (fp1);
	else
		return (fp2);
}

const Fixed	&Fixed::min(Fixed const &fp1, Fixed const &fp2)
{
	if (fp1 > fp2)
		return (fp2);
	else
		return (fp1);
}

const Fixed	&Fixed::max(Fixed const &fp1, Fixed const &fp2)
{
	if (fp1 > fp2)
		return (fp1);
	else
		return (fp2);
}


std::ostream	&operator<<(std::ostream &o, Fixed const &src)
{
	o << src.toFloat();
	return (o);
}
