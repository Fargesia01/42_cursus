#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "#Welcome to PhoneBook!" << std::endl;
	std::cout << "Enter a command: [ADD], [SEARCH], [EXIT]" << std::endl;
  	this->_number = 0;
	this->_oldest = 0; 
	return ;	
}

PhoneBook::~PhoneBook()
{
	return ;
}

void	PhoneBook::search() const
{
	std::string	index;

	if (this->_number == 0)
		std::cout << "No contact currently registered." << std::endl;
	else
	{
		for (int i = 0; i < this->_number; i++)
		{
			std::cout << "|" << std::setw(10) << i;
			this->_contacts[i].show_infos(3);
		}
		std::cout << "Enter contact ID:" << std::endl;
		std::getline(std::cin, index);
		while (index.length() != 1 || index[0] < '0' || index[0] >= this->_number + '0')
		{
			std::cout << "Enter contact ID:" << std::endl;
			std::getline(std::cin, index);
		}
		this->_contacts[index[0] - '0'].show_infos(5);
	}
	return ;
}

void	PhoneBook::add()
{
	if (this->_number == 8)
	{
		this->_contacts[_oldest].set_infos();
		this->_oldest++;
		if (this->_oldest == 8)
			this->_oldest = 0;
	}
	else
	{
		this->_contacts[_number].set_infos();
		this->_number++;
	}
	return ;
}
