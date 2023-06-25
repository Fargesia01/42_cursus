#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cctype>

class	PhoneBook
{
	public :

		PhoneBook();
		~PhoneBook();

		void	add();
		void	search() const;

	private :
		int		_number;
		int		_oldest;
		Contact		_contacts[8];
};

#endif
