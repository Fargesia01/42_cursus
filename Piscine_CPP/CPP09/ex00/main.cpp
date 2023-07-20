#include "BitcoinExchange.hpp"
#include <iostream>


int	main(int argc, char **argv)
{
	if (argc != 2)
		return (BitcoinExchange::file_error());
	BitcoinExchange change(argv[1]);

	change.getTotalValues("input.txt");

}
