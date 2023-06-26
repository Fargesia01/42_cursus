#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>

class BitcoinExchange
{
	public :
		
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange	&operator=(const BitcoinExchange &src);

		int				valueOnDay(const std::string day) const;
		static std::map<int, int>	extractData(std::string filename) const;
		static int			file_error() const;

		std::map<int, int>	getValues() const;
		void			setValues(int, int> values);

	private :

		std::map<int, int> _values;
}

#endif
