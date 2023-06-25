#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
	public :
		
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange	&operator=(const BitcoinExchange &src);

		int	valueOnDay(const std::string day) const;

		std::map<std::string, int>	getValues() const;
		void				setValues(std::map<std::string, int> values);

	private :

		std::map<std::string, int> _values;
}

#endif
