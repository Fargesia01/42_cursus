#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <fstream>

class	Replace
{
	public :

		Replace(void);
		~Replace(void);
		int	open_files(std::string name, std::string s1, std::string s2);

	private :

		int				_output(std::string line, std::string s1, std::string s2);
		std::ifstream	_input_file;
		std::ofstream	_output_file;
};

#endif
