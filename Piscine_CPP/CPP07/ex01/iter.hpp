#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void	iter(T *tab, int size, void(*fToExe)(T const &))
{
	for (int i = 0; i < size; i++)
	{
		fToExe(tab[i]);
	}
}


#endif
