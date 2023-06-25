#include "Span.hpp"

Span::Span(void): _max_size(0)
{
	return ;
}

Span::Span(unsigned int n): _max_size(n), _list(0)
{
	return ;
}

Span::Span(Span const &src)
{
	*this = src;
	return ;
}

Span::~Span(void)
{
	return ;
}

Span &	Span::operator=(Span const &src)
{
	_max_size = src.getSize();
	_list = src.getList();
	return (*this);
}

void	Span::addNumber(int n)
{
	if (_list.size() == _max_size)
		throw std::out_of_range("List is already full");
	this->_list.push_back(n);
	_size++;
	return ;
}

int	Span::shortestSpan() const
{
	std::vector<int>::iterator	it, it2;
	std::vector<int>	tmp = _list;
	int	shortest = this->longestSpan();

	if (_max_size <= 1)
		throw std::logic_error("Not enough element in list.");
	for (it = tmp.begin(); it != tmp.end() && shortest != 0; it++)
	{
		for (it2 = tmp.begin() + 1; it2 < tmp.end() && shortest != 0; it2++)
		{
			if (it != it2 && abs(*it - *it2) < shortest)
				shortest = abs(*it - *it2);
		}
	}
	return (shortest);
}

int	Span::longestSpan() const
{
	int	span;

	span = *std::max_element(_list.begin(), _list.end()) 
		- *std::min_element(_list.begin(), _list.end());
	return (span);
}

int	Span::getMaxSize() const
{
	return (this->_max_size);
}

int	Span::getSize() const
{
	return (this->_size);
}

std::vector<int>	Span::getList() const
{
	return (this->_list);
}

int	Span::sizeLeft() const
{
	return (_max_size - _size);
}
