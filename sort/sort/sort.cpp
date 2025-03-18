#include "sort.h"


void bubbleSort(std::vector<int>& nums)
{
	size_t size = nums.size();
	for (int i = 0; i < size; i++)
	{
		//标定当前序列是否已经为有序
		bool flag = true;
		//扫描元素并且交换
		for (int j = 0; j < size - i - 1; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				std::swap(nums[j], nums[j + 1]);
				flag = false;
			}
		}
		//如果已经有序，提前退出
		if (flag)
		{
			break;
		}
	}
}

void selectSort(std::vector<int>& nums)
{
	int size = nums.size();
	for (int i = 0; i < size - 1; i++)
	{
		int min_elem = nums[i];
		int min_pos = i;
		//查找后面最小的元素
		for (int j = i; j < size; j++)
		{
			if (min_elem > nums[j])
			{
				min_elem = nums[j];
				min_pos = j;
			}
		}
		//交换首元素与最小元素
		std::swap(nums[i], nums[min_pos]);
	}
}

void heapify(std::vector<int>nums, int i)
{

}

void heapSort(std::vector<int>& nums)
{

}