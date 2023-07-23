#include "PmergeMe.hpp"

bool	checkArg(char *arg)
{
	for (int j = 0; arg[j]; j++)
	{
		if (!std::isdigit(arg[j]))
		{
			std::cout << "Error: Not a positive integer" << std::endl;
			return (false);
		}
		if (std::atof(arg) > 2147483647)
		{
			std::cout << "Error: Value too high" << std::endl;
			return (false);
		}
	}
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: Not enough arguments" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		if (!checkArg(argv[i]))
			return (1);
	}
	PmergeMe	pm(argv);
	
	pm.sort();
}
