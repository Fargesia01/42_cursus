#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class	Span
{
	public :

		Span(unsigned int n);
		Span(Span const &src);
		~Span(void);

		Span&	operator=(Span const &src);

		void				addNumber(int n);
		int					shortestSpan() const;
		int					longestSpan() const;
		int					getMaxSize() const;
		int					getSize() const;
		std::vector<int>	getList() const;
		int					sizeLeft() const;

	private :

		Span(void);

		int					_max_size;
		int					_size;
		std::vector<int>	_list;
};

#endif
