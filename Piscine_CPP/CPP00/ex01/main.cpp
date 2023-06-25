#include <iostream>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook book;
	std::string prompt;

	while (1)
	{
		std::cout << ">";
		std::getline(std::cin, prompt);
		if (prompt == "ADD")
			book.add();
		else if (prompt == "SEARCH")
			book.search();
		else if (prompt == "EXIT")
		{
			std::cout << "Procceding to exit the PhoneBook..." << std::endl;
			std::cout << "Done" << std::endl;
			break ;
		}
	}
	return (0);
}
