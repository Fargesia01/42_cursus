#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class	Array
{
	public :
		
		Array<T>(void): _size(0), _array(NULL)
		{
			std::cout << "Array default constructor called." << std::endl;
			return ;
		}

		Array<T>(unsigned int n): _size(n)		
		{
			std::cout << "Array base constructor called." << std::endl;
			if (n < 0)
				throw std::exception();
			this->_array = new T[n];
			return ;
		}

		Array<T>(Array<T> const &src)
		{
			std::cout << "Array copy constructor called." << std::endl;
			*this = src;
			return ;
		}

		~Array<T>(void)
		{
			std::cout << "Array destructor called." << std::endl;
			if (this->_size > 0)
				delete[](this->_array);
		}

		Array<T> &	operator=(Array<T> const &src)
		{
			std::cout << "Array assignation operator called." << std::endl;
			if (this->_size > 0)
				delete[](this->_array);
			this->_size = src.getSize();
			this->_array = new T[this->_size];
			for (int i = 0; i < this->_size; i++)
				this->_array[i] = src[i];
			return (*this);
		}

		T	&operator[](const int i) const
		{
			if (i < 0 || i >= this->_size)
				throw std::exception();
			return (this->_array[i]);
		}

		int	getSize() const
		{
			return (this->_size);
		}

	private :

		int	_size;
		T	*_array;
};

#endif
