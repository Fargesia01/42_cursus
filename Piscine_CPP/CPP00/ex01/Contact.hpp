#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class	Contact
{
	public :

		Contact(void);
		~Contact(void);

		void	set_infos();
		void	show_infos(int n) const;

	private :

		std::string	_infos[5];

		void	_clean_infos();
};

# endif
