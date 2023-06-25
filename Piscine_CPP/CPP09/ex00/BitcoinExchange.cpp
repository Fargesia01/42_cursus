#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
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
	
}

std::map<std::string, int> BitcoinExchange::getValues() const
{
	return (this->_values);
}

void	BitcoinExchange::setValues(std::map<std::string, int> values)
{
	this->values = values;
}
