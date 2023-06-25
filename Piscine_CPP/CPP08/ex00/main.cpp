#include "easyfind.hpp"
#include <vector>

template<typename T>
void	displayIterator( T it, T end )
{
	if (it != end)
		std::cout << "iterator: " << *it << std::endl;
	else
		std::cout << "iterator reached the end of container" << std::endl;
}

int	main( void )
{
	std::vector<int>			vect;
	std::vector<int>::iterator	it;

	try
	{
		for (int i = 1; i < 59; i += 2)
			vect.push_back(i);
		it = easyfind(vect, 43);
		displayIterator(it, vect.end());
		it = easyfind(vect, 42);
		displayIterator(it, vect.end());
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

