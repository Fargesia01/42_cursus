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
	else if (day > _values.end()->first)
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

double	BitcoinExchange::getTotalValues(std::string filename)
{
	std::ifstream	file;
	std::string	line;
	bool		first = true;

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
	}
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
		date = 0;
		if (first)
		{
			first = false;
			continue ;
		}
		date += std::atoi(line.substr(0, 4).c_str()) * 10000;
		date += std::atoi(line.substr(5, 2).c_str()) * 100;
		date += std::atoi(line.substr(8, 2).c_str());
		map[date] = std::atof(line.substr(11, line.length()).c_str());
	}
	return (map);
}

int	BitcoinExchange::file_error()
{
	std::cout << "Error: could not open file." << std::endl;
	return (1);
}

std::map<int, double> BitcoinExchange::getValues() const
{
	return (this->_values);
}

void	BitcoinExchange::setValues(std::map<int, double> values)
{
	this->_values = values;
}
