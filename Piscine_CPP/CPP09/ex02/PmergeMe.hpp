#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>

class PmergeMe
{
	public :

		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &src);
		~PmergeMe(void);

		PmergeMe &operator=(const PmergeMe &src);

		void	sort();

	private :
		
		std::vector<int>		_vec;
		std::vector<std::pair<int, int>>	_tmpVec;
		std::vector<int>		_sortedVec;

		std::list<int>			_list;
		std::list<std::pair<int, int>>	_tmpList;
		std::list<int>			_sortedList;

		int				_straggle;

		PmergeMe(void);
		void	swapPair(int &a, int &b);

		void	createVPairs();
		void	orderVPairs();
		void	sortVPairs();

		void	createLPairs();
		void	orderLPairs();
		void	sortLPairs();
};

#endif
