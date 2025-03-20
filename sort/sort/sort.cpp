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




/**
 * @brief 
 * @param nums 
 * @param n 
 * @param i 
 */
void heapify(std::vector<int>& nums, int n,int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	//找到最大值
	if (left < n && nums[left] > nums[largest])
	{
		largest = left;
	}

	if (right < n && nums[right] > nums[largest])
	{
		largest = right;
	}

	//如果最大值不是根节点，交换，并且递归调整子树
	if (largest != i)
	{
		std::swap(nums[largest], nums[i]);
		heapify(nums, n,largest);
	}
}

void heapSort(std::vector<int>& nums)
{
	int n = nums.size();
	//建堆
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(nums, n,i);
	}
	//排序
	for (int i = n - 1; i >= 0; i--)
	{
		std::swap(nums[0], nums[i]);
		heapify(nums, i, 0);
	}
}