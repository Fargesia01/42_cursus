#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <sys/time.h>
#include <list>
#include <vector>

void	vectorFJSort(std::vector<int> &vec, int left, int right);
void	vectorMerge(std::vector<int> &vec, int left, int mid, int right);
void	vectorInsertSort(std::vector<int> &vec, int left, int right);

void	listMerge(std::list<int> &myList, std::list<int>::iterator left, std::list<int>::iterator mid, std::list<int>::iterator right);
void	listFJSort(std::list<int> &myList, std::list<int>::iterator left, std::list<int>::iterator right);
void	listInsertSort(std::list<int> &myList, std::list<int>::iterator left, std::list<int>::iterator right);

void	printVector(std::vector<int> vec);
void	printList(std::list<int> list);

#endif
