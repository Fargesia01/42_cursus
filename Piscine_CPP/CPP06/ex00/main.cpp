#include "analyse.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	std::string	type;

	if (argc != 2)
	{
		std::cout << "Wrong number of arguments." << std::endl;
		return (0);
	}
	try
	{
		type = getType(argv[1]);
		if (type == "char")
			printChar(argv[1]);
		else if (type == "int")
			printInt(argv[1]);
		else if (type == "float")
			printFloat(argv[1]);
		else if (type == "double")
			printDouble(argv[1]);
		else
		{
			std::cout << "Unrecognized pattern." << std::endl;
			return (0);
		}
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
