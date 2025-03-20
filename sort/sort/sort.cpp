#include "sort.h"


void bubbleSort(std::vector<int>& nums)
{
	size_t size = nums.size();
	for (int i = 0; i < size; i++)
	{
		//�궨��ǰ�����Ƿ��Ѿ�Ϊ����
		bool flag = true;
		//ɨ��Ԫ�ز��ҽ���
		for (int j = 0; j < size - i - 1; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				std::swap(nums[j], nums[j + 1]);
				flag = false;
			}
		}
		//����Ѿ�������ǰ�˳�
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
		//���Һ�����С��Ԫ��
		for (int j = i; j < size; j++)
		{
			if (min_elem > nums[j])
			{
				min_elem = nums[j];
				min_pos = j;
			}
		}
		//������Ԫ������СԪ��
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
	
	//�ҵ����ֵ
	if (left < n && nums[left] > nums[largest])
	{
		largest = left;
	}

	if (right < n && nums[right] > nums[largest])
	{
		largest = right;
	}

	//������ֵ���Ǹ��ڵ㣬���������ҵݹ��������
	if (largest != i)
	{
		std::swap(nums[largest], nums[i]);
		heapify(nums, n,largest);
	}
}

void heapSort(std::vector<int>& nums)
{
	int n = nums.size();
	//����
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(nums, n,i);
	}
	//����
	for (int i = n - 1; i >= 0; i--)
	{
		std::swap(nums[0], nums[i]);
		heapify(nums, i, 0);
	}
}