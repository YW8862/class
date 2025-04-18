#ifndef __SORT_H__
#define __SORT_H__
#include <vector>
#include "types.h"

//template<typename T>
void bubbleSort(std::vector<int> &nums);

void selectSort(std::vector<int>& nums);

void heapSort(std::vector<int>& nums);

void insertSort(std::vector<int>& nums);

void mergeSort(std::vector<int>& nums);

void quickSort(std::vector<int>& nums);

void shellSort(std::vector<int>& nums);

#endif