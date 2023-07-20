#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>

class BitcoinExchange
{
	public :
		
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange	&operator=(const BitcoinExchange &src);
   
		double				valueOnDay(int day);
		void				getTotalValues(std::string filename);
		static std::map<int, double>	extractData(std::string filename);
		static int			file_error();

		std::map<int, double>	getValues() const;
		void			setValues(std::map<int, double> values);

	private :

		std::map<int, double>	_values;

		BitcoinExchange(void);
		static int	dateToInt(std::string date);
		static bool	checkDate(int date);
		static bool	checkLine(std::string line);
};

#endif
