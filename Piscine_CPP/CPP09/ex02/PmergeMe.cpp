#include "PmergeMe.h"

void	vectorInsertSort(std::vector<int> &vec, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int key = vec[i];
		int j = i - 1;
		while (j >= left && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}

void	vectorMerge(std::vector<int> &vec, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (vec[i] <= vec[j])
			i++;
		else
		{
			int value = vec[j];
			int k = j;
			while (k > i)
			{
				vec[k] = vec[k - 1];
				k--;
			}
			vec[i] = value;
			i++;
			mid++;
			j++;
		}
	}
}

void	vectorFJSort(std::vector<int> &vec, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	vectorFJSort(vec, left, mid);
	vectorFJSort(vec, mid + 1, right);
	vectorMerge(vec, left, mid, right);
	vectorInsertSort(vec, left, right);
}

void	listFJSort(std::list<int> &list, std::list<int>::iterator left, std::list<int>::iterator right)
{
	if (std::distance(left, right) <= 1)
		return;

	std::list<int>::iterator mid = std::next(left, std::distance(left, right) / 2);
	listFJSort(list, left, mid);
	listFJSort(list, mid, right);
	listMerge(list, left, mid, right);
	listInsertSort(list, left, right);
}

void	listMerge(std::list<int> &list, std::list<int>::iterator left, std::list<int>::iterator mid, std::list<int>::iterator right)
{
	std::list<int>::iterator	i = left;
	std::list<int>::iterator	j = std::next(mid);

	while (i != mid && j != right)
	{
		if (*i <= *j)
			i++;
		else
		{
			int value = *j;
			list.erase(j);
			list.insert(i, value);
			i++;
			mid++;
			j++;
		}
	}
}

void	listInsertSort(std::list<int> &list, std::list<int>::iterator left, std::list<int>::iterator right)
{
	for (std::list<int>::iterator it = std::next(left); it != std::next(right); ++it)
	{
		int key = *it;
		std::list<int>::iterator j = std::prev(it);
		while (j != left && *j > key)
		{
			*(std::next(j)) = *j;
			j--;
		}
		*(std::next(j)) = key;
	}
}
