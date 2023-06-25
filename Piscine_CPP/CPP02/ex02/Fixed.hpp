#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	public :

		Fixed(void);
		Fixed(Fixed const &src);
		Fixed(int const nb);
		Fixed(float const nb);
		~Fixed(void);

		Fixed 	&operator=(Fixed const &src);

		bool	operator<(Fixed const &fp) const;
		bool	operator>(Fixed const &fp) const;
		bool	operator<=(Fixed const &fp) const;
		bool	operator>=(Fixed const &fp) const;
		bool	operator==(Fixed const &fp) const;
		bool	operator!=(Fixed const &fp) const;

		Fixed	operator+(Fixed const &fp) const;
		Fixed	operator-(Fixed const &fp) const;
		Fixed	operator*(Fixed const &fp) const;
		Fixed	operator/(Fixed const &fp) const;

		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);
		
		static Fixed		&min(Fixed &fp1, Fixed &fp2);
		static const Fixed	&min(Fixed const &fp1, Fixed const &fp2);
		static Fixed		&max(Fixed &fp1, Fixed &fp2);
		static const Fixed	&max(Fixed const &fp1, Fixed const &fp2);

		int			getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int			toInt(void) const;

	private :

		int			_whole;
		static int const	_fp = 8;


};

std::ostream	&operator<<(std::ostream &o, Fixed const &src);

#endif
