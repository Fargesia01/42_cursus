#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename)
{
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src)
{
	this->_values = src.getValues();
}

int	BitcoinExchange::valueOnDay(const std::string day) const
{
	std::map<int, int>::iterator iter = this->values.find(day);

	if (iter == this->values.end())
	{
		return (0);
	}
	else
		return (iter->second);
}

std::map<int, int> BitcoinExchange::extractData(std::string filename) const
{
	std::ifstream		file("data.csv");
	std::map<int, int>	map;
	std::string		line;

	if (!file.is_open())
		return (BitcoinExchange::file_error());
	while(std::getline(file, line))
	{
		std::isstringstream iss(line);
		std::string key;
	}

}

int	BitcoinExchange::file_error() const
{
	std::cout << "Error: could not open file." << std::endl;
	return (1);
}

std::map<int, int> BitcoinExchange::getValues() const
{
	return (this->_values);
}

void	BitcoinExchange::setValues(std::map<int, int> values)
{
	this->values = values;
}
