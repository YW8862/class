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

void heapify(std::vector<int>nums, int i)
{

}

void heapSort(std::vector<int>& nums)
{

}