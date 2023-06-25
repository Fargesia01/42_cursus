#include "Span.hpp"

int main()
{
	Span	test(5);

	test.addNumber(6);
	test.addNumber(3);
	test.addNumber(17);
	test.addNumber(9);
	test.addNumber(11);
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;
	std::cout << test.sizeLeft() << std::endl;
}
