#include <iostream>

int	main()
{
	std::string	string = "string";
	std::string*	ptr = &string;
	std::string&	ref = string;

	std::cout << "Addresse de la string :" << &string << std::endl;
	std::cout << "Addresse du pointeur :" << ptr << std::endl;
	std::cout << "Addresse de la référence :" << &ref << std::endl;

	std::cout << "Valeur de la string :" << string << std::endl;
	std::cout << "Valeur dans le pointeur :" << *ptr << std::endl;
	std::cout << "Valeur dans la référence :" << ref << std::endl;
}
