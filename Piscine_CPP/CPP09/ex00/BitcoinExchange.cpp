#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	_values = extractData(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
	return ;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src)
{
	this->_values = src.getValues();
	return (*this);
}

double	BitcoinExchange::valueOnDay(int day)
{
	std::map<int, double>::iterator iter = _values.begin();

	if (day < _values.begin()->first)
		return (_values.begin()->second);
	if (day > _values.rbegin()->first)
		return (_values.rbegin()->second);
	while (iter != _values.end())
	{

		if (iter->first == day)
			return (iter->second);
		else if (iter->first > day)
		{
			iter--;
			return (iter->second);
		}
		iter++;
	}
	return (0);
}

void	BitcoinExchange::getTotalValues(std::string filename)
{
	std::ifstream	file;
	std::string	line, sDate;
	bool		first = true;
	double		number, valueDay;

	file.open(filename.c_str(), std::ios::in);
	if (file.fail())
	{
		BitcoinExchange::file_error();
		exit(1);
	}
	while (std::getline(file, line))
	{
		if (first)
		{
			first = false;
			continue ;
		}
		if (!checkLine(line))
			continue ;
		number = std::atof(line.substr(12, line.length()).c_str());
		if (number < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		else if (number > 2147483647)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		valueDay = this->valueOnDay(BitcoinExchange::dateToInt(line.substr(0, 10)));
		std::cout << line.substr(0, 10) << " => " << number << " = " << number * valueDay << std::endl;
	}
}

bool	BitcoinExchange::checkLine(std::string line)
{
	if (line.length() < 14)
	{
		std::cout << "Error: line too short => " << line << std::endl;
		return (false);
	}
	for (int i = 0; i < 4; i++)
	{
		if (!std::isdigit(line[i]))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return (false);
		}
	}
	if (line[4] != '-' || line[7] != '-' || line[11] != '|' || line[10] != ' ' || line[12] != ' ')
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (false);
	}
	if (!std::isdigit(line[5]) || !std::isdigit(line[6]) || !std::isdigit(line[8]) || !std::isdigit(line[9]))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (false);
	}
	if (!checkDate(BitcoinExchange::dateToInt(line.substr(0, 10))))
		return (false);
	for (char c : line.substr(13, line.length()))
	{
		if (!std::isdigit(c) && c != '.')
		{
			std::cout << "Error bad input => " << line << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	BitcoinExchange::checkDate(int date)
{
	int day, month, year;

	day = date % 100;
	month = (date / 100) % 100;
	year = date / 10000;
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 0 && day <= 31)
		return (true);
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 0 && day <= 30)
		return (true);
	else if (month == 2 && day > 0 && day <= 28)
		return (true);
	else if (month == 2 && day == 29 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		return (true);
	else
		return (false);
}

std::map<int, double> BitcoinExchange::extractData(std::string filename)
{
	std::ifstream		file;
	std::map<int, double>	map;
	std::string		line;
	bool			first = true;
	int			date;

	file.open(filename.c_str(), std::ios::in);
	if (file.fail())
	{
		BitcoinExchange::file_error();
		exit(1);
	}
	while (std::getline(file, line))
	{
		if (first)
		{
			first = false;
			continue ;
		}
		date = BitcoinExchange::dateToInt(line.substr(0, 10));
		map[date] = std::atof(line.substr(11, line.length()).c_str());
	}
	return (map);
}

int	BitcoinExchange::file_error()
{
	std::cout << "Error: could not open file." << std::endl;
	return (1);
}

int	BitcoinExchange::dateToInt(std::string date)
{
	int idate = 0;

	idate += std::atoi(date.substr(0, 4).c_str()) * 10000;
	idate += std::atoi(date.substr(5, 2).c_str()) * 100;
	idate += std::atoi(date.substr(8, 2).c_str());
	return (idate);
}

std::map<int, double> BitcoinExchange::getValues() const
{
	return (this->_values);
}

void	BitcoinExchange::setValues(std::map<int, double> values)
{
	this->_values = values;
}
