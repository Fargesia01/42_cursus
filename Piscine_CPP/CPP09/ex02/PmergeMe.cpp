#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		this->_vec.push_back(std::atoi(argv[i]));
		this->_list.push_back(std::atoi(argv[i]));
	}
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	return (*this);
}

void	PmergeMe::sort()
{
	this->createVPairs();
	for (int i = 0; i < _tmpVec.size(); i++)
		std::cout << "VECTOR before: " << _tmpVec[i].first << _tmpVec[i].second << std::endl;
	this->orderVPairs();
	for (int i = 0; i < _tmpVec.size(); i++)
		std::cout << "VECTOR after: " << _tmpVec[i].first << _tmpVec[i].second << std::endl;
	
	this->createLPairs();
	for (std::list<std::pair<int, int>>::iterator it = _tmpList.begin(); it != _tmpList.end(); it++)
		std::cout << "LIST: " << it->first << it->second << std::endl;
	this->orderLPairs();
	for (std::list<std::pair<int, int>>::iterator it = _tmpList.begin(); it != _tmpList.end(); it++)
		std::cout << "LIST: " << it->first << it->second << std::endl;

	std::cout << _straggle << std::endl;
}

void	PmergeMe::createLPairs()
{
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		int tmp = *it;
		it++;
		if (it == _list.end())
			break ;
		_tmpList.push_back(std::make_pair(tmp, *it));
	}
	if (_list.size() % 2 != 0)
		_straggle = _list.back();
}

void	PmergeMe::createVPairs()
{
	for (int i = 0; i < _vec.size(); i += 2)
	{
		if (i != _vec.size() - 1)
			_tmpVec.push_back(std::make_pair(_vec[i], _vec[i + 1]));
	}
	if (_vec.size() % 2 != 0)
		_straggle = _vec[_vec.size() - 1];
}

void	PmergeMe::orderLPairs()
{
	for (std::list< std::pair<int, int> >::iterator it = _tmpList.begin(); it != _tmpList.end(); it++)
	{
		if (it->first > it->second)
			swapPair(it->first, it->second);
	}
}

void	PmergeMe::orderVPairs()
{
	for (int i = 0; i < _tmpVec.size(); i++)
	{
		if (_tmpVec[i].first > _tmpVec[i].second)
			swapPair(_tmpVec[i].first, _tmpVec[i].second);
	}
}

void	PmergeMe::sortVPairs()
{
	
}

void	PmergeMe::sortLPairs()
{

}

void	PmergeMe::swapPair(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
