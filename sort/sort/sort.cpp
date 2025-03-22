#include "sort.h"


//void bubbleSort(std::vector<int>& nums)
//{
//	size_t size = nums.size();
//	for (int i = 0; i < size; i++)
//	{
//		//�궨��ǰ�����Ƿ��Ѿ�Ϊ����
//		bool flag = true;
//		//ɨ��Ԫ�ز��ҽ���
//		for (int j = 0; j < size - i - 1; j++)
//		{
//			if (nums[j] > nums[j + 1])
//			{
//				std::swap(nums[j], nums[j + 1]);
//				flag = false;
//			}
//		}
//		//����Ѿ�������ǰ�˳�
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
//		//���Һ�����С��Ԫ��
//		for (int j = i; j < size; j++)
//		{
//			if (min_elem > nums[j])
//			{
//				min_elem = nums[j];
//				min_pos = j;
//			}
//		}
//		//������Ԫ������СԪ��
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
//	//�ҵ����ֵ
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
//	//������ֵ���Ǹ��ڵ㣬���������ҵݹ��������
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
//	//����
//	for (int i = n / 2 - 1; i >= 0; i--)
//	{
//		heapify(nums, n,i);
//	}
//	//����
//	for (int i = n - 1; i >= 0; i--)
//	{
//		std::swap(nums[0], nums[i]);
//		heapify(nums, i, 0);
//	}
//}
//
///**
// * @brief 
// * @param nums��Ҫ��������� 
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
//			//�����ƶ�һλ
//			nums[pos + 1] = nums[pos];
//			pos--;
//		}
//		nums[pos + 1] = key;
//	}
//}
//
////�ϲ���������
//std::vector<int> merge(std::vector<int>leftnums, std::vector<int>rightnums)
//{
//	std::vector<int>result;
//	int left = 0, right = 0;
//	//�ϲ�
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
//	//��������δ��ɣ��ϲ������
//	while (left < leftnums.size())
//	{
//		result.push_back(leftnums[left]);
//		left++;
//	}
//	//����Ұ���δ��ɣ��ϲ��Ұ���
//	while (right < rightnums.size())
//	{
//		result.push_back(rightnums[right]);
//		right++;
//	}
//	return result;
//}
//
////�ݹ�ʵ�ֹ鲢����
//std::vector<int> msort(std::vector<int> nums, int begin, int end)
//{
//	//���ֻ��һ�����ݣ�ֱ�ӷ��ؼ���
//	if (begin == end)
//	{
//		return std::vector<int>{nums[begin]};
//	}
//	// �ݹ黮�����Ұ���
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
////�鲢����
//void mergeSort(std::vector<int>& nums)
//{
//	nums =	msort(nums, 0, nums.size()-1);
//}
//
////�ݹ�ʽ����
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
//		//j����ҵ�һ���Ȼ�׼С��Ԫ��
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
////����
//void quickSort(std::vector<int>& nums)
//{
//	qsort(nums, 0, nums.size() - 1);
//}
//
////ϣ������
//void shellSort(std::vector<int>& nums)
//{
//	//��ʶÿһ�˿���Ĳ�����ֱ������Ϊ1
//	for (int step = nums.size() / 2; step > 0; step /= 2)
//	{
//		//��ÿһ�����ݽ��в�������
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
	//���û�н������������
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
	//����Ϊ�󶥶�
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