#include "PmergeMe.h"

void	printVec(std::vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

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
	std::vector<int>	vec;
	std::list<int>		list;
	timeval			Vstart, Vend;
	timeval			Lstart, Lend;

	if (argc < 2)
	{
		std::cout << "Error: Not enough arguments" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		if (!checkArg(argv[i]))
			return (1);
		vec.push_back(std::atoi(argv[i]));
		list.push_back(std::atoi(argv[i]));
	}

	std::cout << "Before: ";
	printVec(vec);
	gettimeofday(&Vstart, NULL);
	vectorFJSort(vec, 0, vec.size() - 1);
	gettimeofday(&Vend, NULL);
	std::cout << "After: ";
	printVec(vec);

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector<int> : " << (Vend.tv_sec - Vstart.tv_sec) * 10000 << "." << Vend.tv_usec - Vstart.tv_usec << " us" << std::endl;
	
	gettimeofday(&Lstart, NULL);
	listFJSort(list, list.begin(), list.end());
	gettimeofday(&Lend, NULL);

	std::cout << "Time to process a range of " << vec.size() << " elements with std::list<int> : " << (Lend.tv_sec - Lstart.tv_sec) * 10000<< "." << Lend.tv_usec - Lstart.tv_usec << " us" << std::endl;

	return (0);
}
