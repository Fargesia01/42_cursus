#ifndef ANALYSE_HPP
# define ANALYSE_HPP

#include <iostream>

std::string	getType(char *argv);
std::string	speCases(char *argv);
std::string	numType(char *argv);
void		printChar(char *argv);
void		printInt(char *argv);
void		printFloat(char *argv);
void		printDouble(char *argv);

class	WrongLitteralTypeException: public std::exception
{
	public :

		virtual const char* what() const throw();
};

#endif
