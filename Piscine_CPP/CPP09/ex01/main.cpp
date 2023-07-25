#include "RPN.hpp"

int	main(int argc, char **argv)
{
	int	result;

	if (argc != 2)
	{
		std::cout << "Error: Not enough arguments" << std::endl;
		return (1);
	}
	result = compute(argv[1]);
	std::cout << result << std::endl;
}
