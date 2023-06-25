#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template<typename T>
void	swap(T &s1, T &s2)
{
	T	tmp = s1;

	s1 = s2;
	s2 = tmp;
}

template<typename T>
T const	min(T const &s1, T const &s2)
{
	if (s1 < s2)
		return (s1);
	else
		return (s2);
}

template<typename T>
T const max(T const &s1, T const &s2)
{
	if (s1 > s2)
		return (s1);
	else
		return (s2);
}

#endif
