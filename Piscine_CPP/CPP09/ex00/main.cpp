#include "BitcoinExchange.hpp"
#include <iostream>

int	file_error()
{
	std::cout << "Error: could not open file." << std::endl;
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (file_error());
	
}
