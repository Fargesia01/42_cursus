#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base*	generate(void)
{
	int	i = rand();

	if (i % 3 == 0)
		return (new A());
	else if (i % 3 == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base *p)
{
	A *a;
	B *b;
	C *c;

	if ((a = dynamic_cast<A *>(p)))
		std::cout << "Type is A." << std::endl;
	else if ((b = dynamic_cast<B *>(p)))
		std::cout << "Type is B." << std::endl;
	else if ((c = dynamic_cast<C *>(p)))
		std::cout << "Type is C." << std::endl;
	return ;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "Type is A." << std::endl;
	}
	catch(std::exception &e)
	{
		
	}

	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "Type is B." << std::endl;
	}
	catch(std::exception &e)
	{

	}

	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "Type is C." << std::endl;
	}
	catch(std::exception &e)
	{

	}
}

int main()
{
	Base	*base;

	std::cout << "Identifying with pointers" << std::endl;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	std::cout << std::endl << "Identifying with references" << std::endl
		<< std::endl;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;	
}
