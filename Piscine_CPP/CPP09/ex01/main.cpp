#include "RPN.hpp"

int	main(int argc, char **argv)
{
	int	result;

	result = compute(argv[1]);
	std::cout << result << std::endl;
}
