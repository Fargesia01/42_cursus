#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class	NotFoundException: public std::exception
{
	public :

		virtual const char* what() const throw()
		{
			return ("Element not found.");
		}
};

template<typename T>
typename T::iterator	easyfind(T	&src, const int dst)
{
	typename T::iterator	found = find(src.begin(), src.end(), dst);

	if (found == src.end())
		throw NotFoundException();
	return (found);
}

#endif
