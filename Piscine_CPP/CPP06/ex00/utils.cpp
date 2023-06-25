#include "utils.hpp"

int	ft_strlen(char *argv)
{
	int	i = 0;

	while (argv[i])
		i++;
	return (i);
}

bool	isDigit(char src)
{
	if (src < '0' || src > '9')
		return (false);
	else
		return (true);
}

bool	charConvert(double n)
{
	if (n - static_cast<int>(n) != 0 || n > 127 || n < 0)
	   std::cout << "Char : Impossible" << std::endl;
	else if (n <= 31 || n == 127)
		std::cout << "Char : Not printable" << std::endl;
	else
		return (true);
	return (false);
}

bool	intConvert(double n)
{
	return (n <= std::numeric_limits<int>::max()
			&& n >= std::numeric_limits<int>::min()
			&& n != std::numeric_limits<double>::infinity()
			&& n != -std::numeric_limits<double>::infinity()
			&& n != std::numeric_limits<double>::quiet_NaN());	
}

bool floatConvert(double n)
{
	return ((n <= std::numeric_limits<float>::max()
			&& n >= -std::numeric_limits<float>::max())
			|| n == std::numeric_limits<double>::infinity()
			|| n == -std::numeric_limits<double>::infinity()
			|| std::isnan(n));
}
