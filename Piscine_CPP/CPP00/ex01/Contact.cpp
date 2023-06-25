#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::_clean_infos()
{
	this->_infos[0] = "";
	this->_infos[1] = "";
	this->_infos[2] = "";
	this->_infos[3] = "";
	this->_infos[4] = "";
	return ;
}

void	Contact::set_infos()
{
	this->_clean_infos();
	std::cout << "Please enter contact infos:" << std::endl;
	while (this->_infos[0].length() == 0)
	{
		std::cout << "First Name:";
		std::getline(std::cin, this->_infos[0]);
	}
	while (this->_infos[1].length() == 0)
	{
		std::cout << std::endl << "Last Name:";
		std::getline(std::cin, this->_infos[1]);
	}
	while (this->_infos[2].length() == 0)
	{
		std::cout << std::endl << "Nickname:";
		std::getline(std::cin, this->_infos[2]);
	}
	while (this->_infos[3].length() == 0)
	{
		std::cout << std::endl << "Phone Number:";
		std::getline(std::cin, this->_infos[3]);
	}
	while (this->_infos[4].length() == 0)
	{
		std::cout << std::endl << "Darkest Secret:";
		std::getline(std::cin, this->_infos[4]);
	}
}

void	Contact::show_infos(int n) const
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "|";
		if (this->_infos[i].length() > 10)
			std::cout << this->_infos[i].substr(0, 9) << ".";
		else
		{
			std::cout << std::setw(10) << this->_infos[i];
		}
	}
	std::cout << "|" << std::endl;
	return ;
}
