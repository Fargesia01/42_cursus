#include "analyse.hpp"
#include "utils.hpp"

void printDouble(char *argv)
{
	char		charV;
	int			intV;
	float		floatV;
	double		doubleV;

	doubleV = atof(argv);
	if (charConvert(doubleV))
	{
		charV = static_cast<char>(doubleV);
		std::cout << "Char : " << charV << std::endl;
	}
	if (intConvert(doubleV))
	{
		intV = static_cast<int>(doubleV);
		std::cout << "Int : " << intV << std::endl;
	}
	if (floatConvert(doubleV))
	{
		floatV = static_cast<float>(doubleV);
		if (doubleV - static_cast<int>(doubleV) == 0)
			std::cout << "Float : " << floatV  << ".0f" << std::endl;
		else std::cout << "Float : " << floatV << "f" << std::endl;
	}
	if (doubleV - static_cast<int>(doubleV) == 0)
		std::cout << "Double : " << doubleV  << ".0" << std::endl;
	else
		std::cout << "Double : " << doubleV << std::endl;
}

void	printFloat(char *argv)
{
	char		charV;
	int			intV;
	float		floatV;
	double		doubleV;

	floatV = atof(argv);
	if (charConvert(floatV))
	{
		charV = static_cast<char>(floatV);
		std::cout << "Char : " << charV << std::endl;
	}
	if (intConvert(floatV))
	{
		intV = static_cast<int>(floatV);
		std::cout << "Int : " << floatV << std::endl;
	}
	doubleV = static_cast<double>(floatV);
	if (floatV - static_cast<int>(floatV) == 0)
	{
		std::cout << "Float : " << floatV << ".0f" << std::endl;
		std::cout << "Double : " << doubleV << ".0" << std::endl;
	}
	else
	{
		std::cout << "Float : " << floatV  << "f" << std::endl;
		std::cout << "Double : " << doubleV << std::endl;
	}
}

void	printInt(char *argv)
{
	char		charV;
	int			intV;
	float		floatV;
	double		doubleV;

	intV = atoi(argv);
	if (charConvert(intV))
	{
		charV = static_cast<char>(intV);
		std::cout << "Char : " << charV << std::endl;
	}
	std::cout << "Int : " << intV << std::endl;
	floatV = static_cast<float>(intV);
	std::cout << "Float : " << floatV << ".0f" << std::endl;
	doubleV = static_cast<double>(intV);
	std::cout << "Double :" << doubleV << ".0" << std::endl;
}

void	printChar(char *argv)
{
	char		charV;
	int			intV;
	float		floatV;
	double		doubleV;

	charV = argv[0];
	std::cout << "Char : " << charV << std::endl;
	intV = static_cast<int>(charV);
	std::cout << "Int : " << intV << std::endl;
	floatV = static_cast<float>(charV);
	std::cout << "Float : " << floatV  << ".0f" << std::endl;
	doubleV = static_cast<double>(charV);
	std::cout << "Double : " << doubleV << ".0" << std::endl;
}

std::string	getType(char *argv)
{
	std::string	type;

	if	(!argv[0])
		throw WrongLitteralTypeException();
	type = speCases(argv);
	if (type != "")
		return (type);
	else if (argv[0] >= '0' && argv[0] <= '9')
		return (numType(argv));
	else if (argv[0] == '-' && argv[1] >= '0' && argv[1] <= '9')
		return (numType(argv));
	else if (argv[1])
		throw WrongLitteralTypeException();
	else
		return ("char");
}

std::string	speCases(char *argv)
{
	const std::string	fSpe[] = {"inff", "+inff", "-inff", "nanf"};
	const std::string 	dSpe[] = {"inf", "+inf", "-inf", "nan"};

	for (int i = 0; i < 4; i++)
	{
		if (argv == fSpe[i])
			return ("float");
		else if (argv == dSpe[i])
			return ("double");
	}
	return ("");
}

std::string	numType(char *argv)
{
	int	dCount = 0;
	int	fCount = 0;

	for (int i = 0; argv[i]; i++)
	{
		if (argv[i] == '.' && (!argv[i + 1] || !isDigit(argv[i + 1])))
			throw WrongLitteralTypeException();
		else if (argv[i] == '.')
			dCount++;
		else if (argv[i] == 'f' && i != ft_strlen(argv) - 1)
			throw WrongLitteralTypeException();
		else if (argv[i] == '-' && i != 0)
			throw WrongLitteralTypeException();
		else if (!isDigit(argv[i]) && argv[i] != 'f' && argv[i] != '-')
			throw WrongLitteralTypeException();

		if (argv[i] == 'f' && dCount != 1)
			throw WrongLitteralTypeException();
		else if (argv[i] == 'f')
			return ("float");
	}
	if (dCount > 1)
		throw WrongLitteralTypeException();
	if (dCount == 1)
		return ("double");
	else
		return ("int");
}

const char*	WrongLitteralTypeException::what() const throw()
{
	return ("Incorrect argument type.");
}
