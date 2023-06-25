#include <iostream>
#include <fstream>
#include "Replace.hpp"

Replace::Replace(void)
{
	std::cout << "Default Replace constructor." << std::endl;
	return ;
}

Replace::~Replace(void)
{
	std::cout << "Default Replace Destructor." << std::endl;
	return ;
}

int	Replace::open_files(std::string name, std::string s1, std::string s2)
{
	std::string	text;
	std::string	line;
	std::string	out_name = name;

	if (this->_input_file.is_open())
		this->_input_file.close();
	if (this->_output_file.is_open())
		this->_output_file.close();
	if (name == "")
		return (1);
	out_name += ".replace";
	this->_input_file.open(name);
	this->_output_file.open(out_name);
	while (std::getline(this->_input_file, line))
		this->_output(line, s1, s2);
	this->_input_file.close();
	this->_output_file.close();
	return (0);
}

int	Replace::_output(std::string line, std::string s1, std::string s2)
{
	for	(int i = 0; i < line.length(); i++)
	{
		if (!line.compare(i, s1.length(), s1))
		{
			line.erase(i, s1.length());
			line.insert(i, s2);
		}
	}
	this->_output_file << line;
	this->_output_file << "\n";
	return (0);
}
