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
	
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;

	private :

		int			_whole;
		static int const	_fp = 8;


};

std::ostream	&operator<<(std::ostream &o, Fixed const &src);

#endif
