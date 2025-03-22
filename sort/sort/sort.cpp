#include "sort.h"


//void bubbleSort(std::vector<int>& nums)
//{
//	size_t size = nums.size();
//	for (int i = 0; i < size; i++)
//	{
//		//标定当前序列是否已经为有序
//		bool flag = true;
//		//扫描元素并且交换
//		for (int j = 0; j < size - i - 1; j++)
//		{
//			if (nums[j] > nums[j + 1])
//			{
//				std::swap(nums[j], nums[j + 1]);
//				flag = false;
//			}
//		}
//		//如果已经有序，提前退出
//		if (flag)
//		{
//			break;
//		}
//	}
//}
//
//void selectSort(std::vector<int>& nums)
//{
//	int size = nums.size();
//	for (int i = 0; i < size - 1; i++)
//	{
//		int min_elem = nums[i];
//		int min_pos = i;
//		//查找后面最小的元素
//		for (int j = i; j < size; j++)
//		{
//			if (min_elem > nums[j])
//			{
//				min_elem = nums[j];
//				min_pos = j;
//			}
//		}
//		//交换首元素与最小元素
//		std::swap(nums[i], nums[min_pos]);
//	}
//}
//
//
//
//
///**
// * @brief 
// * @param nums 
// * @param n 
// * @param i 
// */
//void heapify(std::vector<int>& nums, int n,int i)
//{
//	int largest = i;
//	int left = 2 * i + 1;
//	int right = 2 * i + 2;
//	
//	//找到最大值
//	if (left < n && nums[left] > nums[largest])
//	{
//		largest = left;
//	}
//
//	if (right < n && nums[right] > nums[largest])
//	{
//		largest = right;
//	}
//
//	//如果最大值不是根节点，交换，并且递归调整子树
//	if (largest != i)
//	{
//		std::swap(nums[largest], nums[i]);
//		heapify(nums, n,largest);
//	}
//}
//
//void heapSort(std::vector<int>& nums)
//{
//	int n = nums.size();
//	//建堆
//	for (int i = n / 2 - 1; i >= 0; i--)
//	{
//		heapify(nums, n,i);
//	}
//	//排序
//	for (int i = n - 1; i >= 0; i--)
//	{
//		std::swap(nums[0], nums[i]);
//		heapify(nums, i, 0);
//	}
//}
//
///**
// * @brief 
// * @param nums需要排序的数字 
// */
//void insertSort(std::vector<int>& nums)
//{
//	int n = nums.size();
//	for (int i = 1; i < n; i++)
//	{
//		int key = nums[i];
//		int pos = i - 1;
//		while (pos >= 0 && nums[pos] >= key)
//		{
//			//往后移动一位
//			nums[pos + 1] = nums[pos];
//			pos--;
//		}
//		nums[pos + 1] = key;
//	}
//}
//
////合并两个数组
//std::vector<int> merge(std::vector<int>leftnums, std::vector<int>rightnums)
//{
//	std::vector<int>result;
//	int left = 0, right = 0;
//	//合并
//	while (left < leftnums.size() && right < rightnums.size())
//	{
//		if (leftnums[left] <= rightnums[right])
//		{
//			result.push_back(leftnums[left]);
//			left++;
//		}
//		else
//		{
//			result.push_back(rightnums[right]);
//			right++;
//		}
//	}
//	//如果左半区未完成，合并左半区
//	while (left < leftnums.size())
//	{
//		result.push_back(leftnums[left]);
//		left++;
//	}
//	//如果右半区未完成，合并右半区
//	while (right < rightnums.size())
//	{
//		result.push_back(rightnums[right]);
//		right++;
//	}
//	return result;
//}
//
////递归实现归并排序
//std::vector<int> msort(std::vector<int> nums, int begin, int end)
//{
//	//如果只有一个数据，直接返回即可
//	if (begin == end)
//	{
//		return std::vector<int>{nums[begin]};
//	}
//	// 递归划分左右半区
//	std::vector<int>leftnums;
//	std::vector<int>rightnums;
//	if (begin < end)
//	{
//		int mid = (begin + end) / 2;
//		leftnums = msort(nums, begin, mid);
//		rightnums = msort(nums, mid + 1, end);
//	}
//	
//	return merge(leftnums,rightnums);
//}
//
////归并排序
//void mergeSort(std::vector<int>& nums)
//{
//	nums =	msort(nums, 0, nums.size()-1);
//}
//
////递归式快排
//void qsort(std::vector<int>&nums, int begin, int end)
//{
//	int cnt = end - begin + 1;
//	if (cnt <= 1)
//	{
//		return;
//	}
//	int key = nums[end];
//	int i = 0, j = 0;
//	while (i < cnt && j < cnt)
//	{
//		//j向后找第一个比基准小的元素
//		while (nums[j] > key)
//		{
//			j++;
//		}
//		std::swap(nums[i],nums[j]);
//		i++;
//	}
//	qsort(nums, begin, i);
//	qsort(nums, i + 1, end);
//}
//
////快排
//void quickSort(std::vector<int>& nums)
//{
//	qsort(nums, 0, nums.size() - 1);
//}
//
////希尔排序
//void shellSort(std::vector<int>& nums)
//{
//	//标识每一趟跨过的步数，直到步数为1
//	for (int step = nums.size() / 2; step > 0; step /= 2)
//	{
//		//对每一组数据进行插入排序
//		for (int i = step; i < nums.size(); i++)
//		{
//			int key = nums[i];
//			int j = i;
//			for (; j >= step && key < nums[j - step]; j -= step)
//			{
//				nums[j] = nums[j - step];
//			}
//			nums[j] = key;
//		}
//	}
//}

void bubbleSort(std::vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		bool sorted = true;
		for (int j = 1; j < nums.size() - i; j++)
		{
			if (nums[j] < nums[j - 1])
			{
				std::swap(nums[j], nums[j - 1]);
				sorted = false;
			}
		}
		if (sorted)
		{
			return;
		}
	}
}

void selectSort(std::vector<int>& nums)
{
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		int maxnum = nums[0];
		int maxpos = 0;
		for (int j = 0; j < size - i; j++)
		{
			if (nums[j] > maxnum)
			{
				maxnum = nums[j];
				maxpos = j;
			}
		}
		std::swap(nums[size - i], nums[maxpos]);
	}
}

void heapfy(std::vector<int> &nums, int i, int n)
{
	int largestpos = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left<n && nums[left]>nums[largestpos])
	{
		largestpos = left;
	}
	if (right<n && nums[right]>nums[largestpos])
	{
		largestpos = right;
	}
	//如果没有交换，调整完成
	if (largestpos == i)
	{
		return;
	}
	std::swap(nums[i],nums[largestpos]);
	heapfy(nums, largestpos,n);
}

void heapSort(std::vector<int>& nums)
{
	int n = nums.size();
	//调整为大顶堆
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapfy(nums, i, n);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		std::swap(nums[0], nums[i]);
		heapfy(nums, 0, i);
	}
}

void insertSort(std::vector<int>& nums)
{
	int size = nums.size();
	for (int i = 1; i < size; i++)
	{
		int key = nums[i];
		int j = i;
		for (; j >= 0&&nums[j] > key; j--)
		{
			nums[j + 1] = nums[j];
		}
		nums[j] = key;
	}
}